#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        vector<ll> validK(n+1,1); 

        for(int i=0; i<30; i++){
            vector<int>factors(n+1);
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(arr[j] & (1LL << i)){
                    cnt++;
                }
            }
            for(int j=1; j<=n; j++){
                if(cnt%j == 0){
                    factors[j] = 1;
                }
            }
            for(int j=1; j<=n; j++){
                validK[j] = validK[j] & factors[j];
            }
        }

        for(int i=1; i<=n; i++){
            if(validK[i]){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}
