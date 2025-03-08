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
        
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        long long ans = 2;
        while(1){
            set<long long> st;

            for(int i=0; i<n; i++){
                st.insert(a[i] % ans);
            }

            if(st.size() == 2){
                break;
            }
            ans *= 2;
        }

        cout<<ans<<"\n";
    }

    return 0;
}
