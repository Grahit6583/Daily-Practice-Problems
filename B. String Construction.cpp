#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k > n - 2) {
        cout << "-1\n";
        return;
    }

    int b = n - k;                 
    int ones_total = (n + 1) / 2;  
    int zeros_total = n / 2;       

    int ones_blocks = (b + 1) / 2; 
    int zeros_blocks = b / 2;      

    int extra_ones = ones_total - ones_blocks;
    int extra_zeros = zeros_total - zeros_blocks;

    string s = "";
    for (int i = 0; i < b; i++) {
        int count = 1; 
        
        if (i == 0) count += extra_ones;  
        if (i == 1) count += extra_zeros; 
        
        char ch = (i % 2 == 0) ? '1' : '0';
        s.append(count, ch);
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}