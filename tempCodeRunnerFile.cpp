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

        int pos = 0;
        int neg = 0;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            if(x > 0){
                pos++;
            }
            else{
                neg++;
            }
        }

        int op = 0;
        while(pos < neg || neg % 2 == 1){
            op++;
            pos++;
            neg--;
        }

        cout<<op<<"\n";
    }

    return 0;
}
