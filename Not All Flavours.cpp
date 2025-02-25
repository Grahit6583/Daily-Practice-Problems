#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        unordered_map<int,int> last_ocurr;

        for(int i=1; i<=k; i++){
            last_ocurr[i] = -1;
        }

        int maxi = 0;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            maxi = max(maxi,i-last_ocurr[x]-1);

            last_ocurr[x] = i;
        }

        for(int i=1; i<=k; i++){
            maxi = max(maxi, n-last_ocurr[i]-1);
        }

        cout<<maxi<<"\n";
    }

    return 0;
}