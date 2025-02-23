#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        set<pair<int,int>> st;
        for(int i=0; i<k; i++){
            int r,c;
            cin>>r>>c;

            st.insert({r,c});
        }

        int cnt = st.size() * 4;

        for(auto it : st){
            if(st.count({it.first-1,it.second})){
                cnt--;
            }
            if(st.count({it.first+1,it.second})){
                cnt--;
            }
            if(st.count({it.first,it.second-1})){
                cnt--;
            }
            if(st.count({it.first,it.second+1})){
                cnt--;
            }
        }

        cout<<cnt<<"\n";
    }

    return 0;
}