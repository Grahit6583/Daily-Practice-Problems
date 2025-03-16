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
        
        int maxi = INT_MIN;
        int cnt = 0;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x == 1){
                maxi = max(maxi,cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        maxi = max(maxi,cnt);
        cout<<maxi<<"\n";
    }

    return 0;
}
