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

        int sum = 0;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            sum ^= x;
        }

        if(n % 2 == 1){
            cout<<sum<<"\n";
        }
        else{
            if(sum == 0){
                cout<<sum<<"\n";
            }
            else{
                cout<<-1<<"\n";
            }
        }
    }

    return 0;
}
