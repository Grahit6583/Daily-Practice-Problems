#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        vector<vector<int>> cnt(100001,vector<int>(2,0));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            cnt[arr[i]][i%2]++;
        }

        sort(arr.begin(),arr.end());

        for (int i = 0; i < n; ++i){
            cnt[arr[i]][i % 2]--;
        }

        bool flag = true;
        for(int i=0; i<n; i++){
            if(cnt[arr[i]][0] !=0 || cnt[arr[i]][1] != 0){
                flag = false;
                cout<<"NO\n";
                break;
            }
        }

        if(flag){
            cout<<"YES\n";
        }
    }

    return 0;
}