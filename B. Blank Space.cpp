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

        int cnt=0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x == 0){
                cnt++;
            }
            else{
                maxi = max(maxi,cnt);
                cnt = 0;
            }
        }
        maxi = max(maxi,cnt);
        cout<<maxi<<"\n";
    }

    return 0;
}
