#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll m;
    cin>>m;

    vector<ll> usbPort;
    vector<ll> psPort;

    for(int i=0; i<m; i++){
        ll x;
        string s;
        cin>>x;
        cin>>s;

        if(s == "USB"){
            usbPort.push_back(x);
        }else{
            psPort.push_back(x);
        }

    }

    sort(usbPort.begin(),usbPort.end());
    sort(psPort.begin(),psPort.end());

    ll l = usbPort.size();
    ll n = psPort.size();

    ll computer = 0;
    ll amount = 0;
    int i = 0, j = 0;

    // a-only ports: exclusive claim on cheapest USB mice
    for (; i < l && a > 0; i++, a--) {
        computer++;
        amount += usbPort[i];
    }

    // b-only ports: exclusive claim on cheapest PS/2 mice
    for (; j < n && b > 0; j++, b--) {
        computer++;
        amount += psPort[j];
    }

    // now merge the true leftovers for the shared (c) ports
    for (; i < l && j < n && c > 0; c--) {
        if (usbPort[i] <= psPort[j]) {
            computer++;
            amount += usbPort[i++];
        } else {
            computer++;
            amount += psPort[j++];
        }
    }
    while (i < l && c > 0) { computer++; amount += usbPort[i++]; c--; }
    while (j < n && c > 0) { computer++; amount += psPort[j++]; c--; }

    cout << computer << " " << amount << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}