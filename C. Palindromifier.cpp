#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;

    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        cout<<3<<"\n";
        cout<<"L 2\n";
        cout<<"R 2\n";
        n *= 2;
        cout<<"R "<<n-1<<"\n";
    }

    return 0;
}