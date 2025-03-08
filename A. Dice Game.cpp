#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int a,b;
    cin>>a>>b;

    int priyansh = 0;
    int priyam = 0;
    int draw = 0;

    for(int i=1; i<=6; i++){
        int x = abs(a-i);
        int y = abs(b-i);

        if(x<y){
            priyansh++;
        }
        else if(y<x){
            priyam++;
        }
        else{
            draw++;
        }
    }

    cout<<priyansh<<" "<<draw<<" "<<priyam;

    return 0;
}