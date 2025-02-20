#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int k=1; k<=t; k++){
        int n,r;
        cin>>r>>n;
        set<pair<int,int>> st;

        for(int i=0; i<n; i++){
            int j,l;
            cin>>j>>l;
            st.insert({j,l});
        }

        if(st.size() == n){
            cout<<"Scenario #"<<k<<": possible\n";
        }
        else
        {
            cout<<"Scenario #"<<k<<": impossible\n";
        }
    }
}