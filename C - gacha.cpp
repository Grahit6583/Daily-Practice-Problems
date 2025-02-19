#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    vector<string> arr(n);
    set<string> st;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }

    cout<<st.size();
}