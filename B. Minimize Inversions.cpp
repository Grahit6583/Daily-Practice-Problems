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

        vector<pair<int,int>> a(n);

        for(int i=0; i<n; i++){
            cin>>a[i].first;
        }

        for(int i=0; i<n; i++){
            cin>>a[i].second;
        }

        sort(a.begin(),a.end());

        for(int i=0; i<n; i++){
            cout<<a[i].first<<" ";
        }

        cout<<"\n";

        for(int i=0; i<n; i++){
            cout<<a[i].second<<" ";
        }

        cout<<"\n";
    }

    return 0;
}
