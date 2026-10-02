#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll h, c, t;
    cin >> h >> c >> t;

    // Edge Case 1: Target is hotter than or equal to hot water
    if (t >= h) {
        cout << 1 << endl;
        return;
    }
    
    // Edge Case 2: Target is less than or equal to the average midpoint
    if (2 * t <= h + c) {
        cout << 2 << endl;
        return;
    }

    // Binary search for the number of pairs (k)
    // Total cups will be 2*k + 1
    ll l = 0, r = 1e9; 
    ll best_k = 0;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        
        // Formula: ((mid + 1)*h + mid*c) / (2*mid + 1) >= t
        // Cross-multiplying to avoid float division:
        if ((mid + 1) * h + mid * c >= t * (2 * mid + 1)) {
            best_k = mid; // This mid yields a temp >= t, keep it as a candidate
            l = mid + 1;  // Try to get closer to t by increasing k (lowering temp)
        } else {
            r = mid - 1;  // Temperature dropped below t, turn back
        }
    }

    // The optimal odd answer is either at best_k or best_k + 1
    ll k1 = best_k;
    ll k2 = best_k + 1;

    // We must compare which one is genuinely closer to t.
    // Absolute difference for k1: |((k1+1)h + k1*c)/(2k1+1) - t|
    // Absolute difference for k2: |((k2+1)h + k2*c)/(2k2+1) - t|
    // We cross-multiply to compare them purely using integers.
    
    ll representation_k1 = abs(((k1 + 1) * h + k1 * c) * (2 * k2 + 1) - t * (2 * k1 + 1) * (2 * k2 + 1));
    ll representation_k2 = abs(((k2 + 1) * h + k2 * c) * (2 * k1 + 1) - t * (2 * k1 + 1) * (2 * k2 + 1));

    // Choose the candidate with the smaller absolute difference.
    // If tied, choose the smaller number of cups (k1).
    if (representation_k1 <= representation_k2) {
        cout << 2 * k1 + 1 << endl;
    } else {
        cout << 2 * k2 + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}