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

        int a = 1; 
        int b = n-1;
        for(int i=2; i*i <= n; i++){
            if(n%i == 0){
                a = n/i;
                b = n-a;
                break;
            }
        }
        cout<<a<<" "<<b<<"\n";
    }

    return 0;
}
