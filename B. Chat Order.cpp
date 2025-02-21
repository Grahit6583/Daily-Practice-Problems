#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    vector<string> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    set<string> st;
    for(int i=n-1; i>=0; i--){
        if(st.find(vec[i]) == st.end()){
            st.insert(vec[i]);
            cout<<vec[i]<<"\n";
        }
    }

    return 0;
}