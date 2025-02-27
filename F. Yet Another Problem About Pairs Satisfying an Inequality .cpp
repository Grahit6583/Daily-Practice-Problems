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

        vector<long long> vec(n+1), b;
        long long res = 0;
        for(int i=1; i<=n; i++){
            cin>>vec[i];

            if(i > vec[i]){
                b.push_back(i);

                res += lower_bound(b.begin(),b.end(),vec[i])-b.begin();
            }
        }

        cout<<res<<"\n";
    }

    return 0;
}