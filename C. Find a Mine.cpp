#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll ask(ll x,ll y){
    cout<<"? "<<x<<" "<<y<<endl;
    cout.flush();

    ll d;
    cin>>d;
    return d;
}

void answer(ll x,ll y){
    cout<<"! "<<x<<" "<<y<<endl;
    cout.flush();
}

void solve(){

    ll n,m;
    cin>>n>>m;

    ll d = ask(1,1);

    ll lx = max(1LL, d + 2 - m);
    ll ly = d + 2 - lx;

    ll rx = min(n, d + 1);
    ll ry = d + 2 - rx;

    ll p = ask(lx,ly);
    ll q = ask(rx,ry);

    ll x1 = lx + p/2;
    ll y1 = ly - p/2;

    ll res = ask(x1,y1);

    if(res==0){
        answer(x1,y1);
    }
    else{
        ll x2 = rx - q/2;
        ll y2 = ry + q/2;

        answer(x2,y2);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}