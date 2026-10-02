#include<bits/stdc++.h>

using namespace std;

void factors(int n, map<int,int> &mp){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
                mp[i]++;
            }
        }
    } 
    if(n > 1){
        mp[n]++;
    }

    return ;
}

bool solve(vector<int> &arr,int n){
    map<int,int> mp;

    for(int i=0; i<n; i++){
        factors(arr[i],mp);
    }

    for(auto it : mp){
        if(it.second % n != 0){
            return false;
        }
    }

    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        if(solve(arr,n)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}