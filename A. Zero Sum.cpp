#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    int sum = 0;
    int neg=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
        if(arr[i] == -1){
            neg++;
        }
    }

    if(n%2 == 1){
        cout<<"NO\n";
        return;
    }
    if(sum == 0){
        cout<<"Yes\n";
        return;
    }

    if((neg % 2) == ((n/2) % 2))
        cout << "Yes\n";
    else
        cout << "NO\n";
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