#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> customers(m);
    multiset<int> st;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st.insert(x);
    }

    for(int i=0; i<m; i++){
        int k;
        cin>>k;
        auto ind = st.upper_bound(k);
        if(ind == st.begin()){
            cout<<-1<<"\n";
        }
        else{
            --ind;
            cout<<*ind<<"\n";
            st.erase(ind);
        }
    }

    return 0;
}