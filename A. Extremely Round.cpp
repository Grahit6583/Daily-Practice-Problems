#include<bits/stdc++.h>

using namespace std;

bool check(int i){
    long long zero = 0;
    long long digit = 0;

    while(i){
        if(i % 10 == 0){
            zero++;
        }
        digit++;

        i /= 10;
    }

    return digit-1 == zero;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<long long> round;
    for(long long i=1; i<= 999999; i++){
        if(check(i)){
            round.push_back(i);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 

        int ans  = 0;
        for(int i=0; i<round.size(); i++){
            if(round[i] <= n){
                ans++;
            }
            else{
                break;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
