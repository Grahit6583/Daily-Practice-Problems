#include<bits/stdc++.h>

using namespace std;

long long solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<bool> eligible(n,true);

    long long sum = 0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    for(int i=29; i>=0; i--){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(eligible[j] && (arr[j]>>i)%2){
                cnt++;
            }
        }

        if(cnt >= 2){
            for(int j=0; j<n; j++){
                if(eligible[j] && (arr[j]>>i)%2==0){
                    eligible[j] = false;
                }
            }
        }
    }

    long long ans = (2>>30)-1;
    int cnt = 0;

    for(int i=0; i<n; i++){
        if(eligible[i]){
            ans &= arr[i];
            cnt++;
        }
        if(cnt == 2){
            break;
        }
    }

    return (sum-ans*2);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        cout<<solve()<<"\n";
    }

    return 0;
}
