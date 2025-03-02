#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    vector<int> dx = {-1,1,-1,1};
    vector<int> dy = {1,1,-1,-1};
    while(t--){
        int a,b;
        cin>>a>>b;

        int xk, yk;
        cin>>xk>>yk;

        int xq, yq;
        cin>>xq>>yq;

        set<pair<int,int>> k_hit, q_hit;
        for(int i=0; i<4; i++){
            k_hit.insert({xk + dx[i]*a, yk + dy[i]*b});
            k_hit.insert({xk + dx[i]*b, yk + dy[i]*a});

            q_hit.insert({xq + dx[i]*a, yq + dy[i]*b});
            q_hit.insert({xq + dx[i]*b, yq + dy[i]*a});
        }

        int ans = 0;
        for(auto it : k_hit){
            if(q_hit.find(it) != q_hit.end()){
                ans++;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}