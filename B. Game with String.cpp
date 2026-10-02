#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
string s;
    cin >> s;
    int n = s.size();

    vector<int> best(26, 0);
    static int cnt[26][26];

    for (int d = 0; d < n; d++) {
        memset(cnt, 0, sizeof(cnt));

        // Fill pair counts for this distance d
        for (int i = 0; i < n; i++) {
            int c1 = s[i] - 'a';
            int c2 = s[(i + d) % n] - 'a';
            cnt[c1][c2]++;
        }

        // For each starting letter c1, count how many c2's are unique
        for (int c1 = 0; c1 < 26; c1++) {
            int p = 0;
            for (int c2 = 0; c2 < 26; c2++)
                if (cnt[c1][c2] == 1) p++;
            best[c1] = max(best[c1], p);
        }
    }

    long long total = 0;
    for (int c1 = 0; c1 < 26; c1++) total += best[c1];

    double ans = (double)total / n;
    printf("%.15f\n", ans);
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}