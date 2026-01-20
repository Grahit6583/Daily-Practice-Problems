#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n, q;
    cin >> n >> q;
    vector<string> forest(n);
    for(int i = 0; i < n; i++){
        cin>>forest[i];
    }
    vector<vector<int>> pref(n,vector<int>(n,0));

    for(int i=0; i<n; i++){	
        for(int j=0; j<n; j++){
            int val = (forest[i][j] == '*' ? 1 : 0);
            int top = (i > 0) ? pref[i-1][j] : 0;
            int left = (j > 0) ? pref[i][j-1] : 0;
            int topLeft = (i > 0 && j > 0) ? pref[i-1][j-1] : 0;
            
            pref[i][j] = val + top + left - topLeft;
        }
    }


    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int ans = pref[x2][y2];
        if(x1>0){
            ans -= pref[x1-1][y2];
        }
        if(y1 > 0){
            ans -= pref[x2][y1-1];
        }
        if(x1 > 0 && y1 > 0){
            ans += pref[x1-1][y1-1];
        }
        cout<<ans<<"\n";
    }

    return 0;
}
