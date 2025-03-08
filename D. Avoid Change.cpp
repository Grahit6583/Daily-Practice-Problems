#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k,credit;
    cin>>k>>credit;

    int l = 0;
    int r = 10;

    int ans = 0;
    for(int i=1; i<=10; i++){
        if((k*i)%10 == 0 || (k*i) % 10 == credit){
            ans = i;
            break;
        }
    }

    cout<<ans;

    return 0;
}
