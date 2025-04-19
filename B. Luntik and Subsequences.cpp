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

        int cnt_0 = 0;
        int cnt_1 = 0;

        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            if(x == 1){
                cnt_1++;
            }
            else if(x == 0){
                cnt_0++;
            }
        }

        long long ways = pow(2,cnt_0) * cnt_1;
        cout<<ways<<"\n";
    }

    return 0;
}
