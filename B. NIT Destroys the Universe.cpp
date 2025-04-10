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
        
        bool flag = false;
        int cnt = 0;

        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x != 0){
                flag = true;
            }
            else{
                if(flag){
                    cnt++;
                }
                flag = false;
            }
        }

        if(flag){
            cnt++;
        }

        if(cnt == 0){
            cout<<cnt<<"\n";
        }
        else if(cnt == 1){
            cout<<cnt<<"\n";
        }
        else{
            cout<<2<<"\n";
        }
    }

    return 0;
}
