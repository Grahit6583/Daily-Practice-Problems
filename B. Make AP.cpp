#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;

        bool ans = false;

        long long new_a = 2*b - c;
        if(new_a/a > 0 && new_a % a == 0){
            ans = true;
        }
        long long new_b = (c+a)/2;
        if(new_b/b > 0 && new_b % b == 0 && (c-a)%2 == 0){
            ans = true;
        }
        long long new_c = 2*b-a;
        if(new_c/c > 0 && new_c % c == 0){
            ans = true;
        }

        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}
