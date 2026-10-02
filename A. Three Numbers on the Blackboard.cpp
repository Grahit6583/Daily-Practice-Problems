#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;

    vector<ll> v = {a, b, c};

    sort(v.begin(), v.end());

    if(v[0]+v[1] < v[2]){
        cout<<max({v[0],v[1],v[0]+v[1]}) - min({v[0],v[1],v[0]+v[1]})<<"\n";
        return;
    }


    cout<<max({v[0],v[1],v[2]}) - min({v[0],v[1],v[2]})<<"\n";

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