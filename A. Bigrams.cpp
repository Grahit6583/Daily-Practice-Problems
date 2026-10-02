#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int k;
    cin>>k;

    vector<int> arr(k);
    for(int i=0; i<k; i++){
        cin>>arr[i];
    }

    int two = 0;

    for(int i=0; i<k; i++){
        if(arr[i] >= 3){
            cout<<"YES\n";
            return;
        }
        else if(arr[i] == 2){
            two++;
        }
        if(two >= 2){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}