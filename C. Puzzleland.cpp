#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    set<int> st;

    int p;
    cin>>p;

    for(int i=0; i<p; i++){
        int x;
        cin>>x;

        st.insert(x);
    }

    int q;
    cin>>q;

    for(int i=0; i<q; i++){
        int x;
        cin>>x;

        st.insert(x);
    }

    if(st.size() == n){
        cout<<"I become the guy.";
    }
    else{
        cout<<"Oh, my keyboard!";
    }

    return 0;
}
