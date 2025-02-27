#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int>> b;
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }

        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        int j;
        for(int i=0; i<n; ){
            j=i;
            while(i<n && vec[i] == vec[j]){
                i++;
            }
            b.push_back({vec[j],i-j});
        }

        int m = b.size();
        int ans = b[0].second;
        for(int i=1; i<m; i++){
            if(b[i].first + 1 == b[i-1].first){
                ans = ans + max(b[i].second-b[i-1].second, 0);
            }
            else{
                ans = ans + b[i].second;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}