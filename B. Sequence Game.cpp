#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        vector<long long> b(n), a;
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        a.push_back(b[0]);
        for(int i=1; i<n; i++){
            if(b[i] >= b[i-1]){
                a.push_back(b[i]);
            }
            else{
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
        }
        int k = a.size();
        cout<<k<<"\n";
        for(int i=0; i<k; i++){
            cout<<a[i]<<" ";
        }

        cout<<"\n";
    }


    return 0;
}
