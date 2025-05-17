#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,r,b;
        cin>>n>>r>>b;

        int rn = r/(b+1);
        int rem = r%(b+1);

        for(int i=0; i<(b+1); i++){
            for(int j=1; j<=rn; j++){
                cout<<"R";
            }
            if(rem > 0){
                cout<<"R";
                rem--;
            }
            if(i != b){
                cout<<"B";
            }
        }
        cout<<"\n";
    }

    return 0;
}
