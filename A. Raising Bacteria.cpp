#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int x;
    cin>>x;

    int c = 0;
    
    for(int i=0; i<32; i++){
        if((1<<i)&x){
            c++;
        }
    }

    cout<<c;

    return 0;
}
