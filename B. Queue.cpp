#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin >> n;

    vector<long long> a(n + 2), Min(n + 3);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Build suffix minimum array
    Min[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        Min[i] = min(a[i], Min[i + 1]);
    }

    // For each i, binary search on j
    for (int i = 1; i <= n; i++) {
        int l = i + 1, r = n;
        int pos = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (Min[mid] < a[i]) {
                pos = mid;      // valid, try to go right
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (pos == -1) {
            cout << -1;
        } else {
            cout << pos - i - 1;
        }

        if (i < n) cout << " ";
    }


    return 0;
}