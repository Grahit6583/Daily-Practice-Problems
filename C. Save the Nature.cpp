#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool check(ll prefix, vector<ll> &arr,
           ll x, ll a, ll y, ll b,
           ll k)
{
    ll lcm = a / gcd(a,b) * b;

    ll acnt = prefix/a - prefix/lcm;
    ll bcnt = prefix/b - prefix/lcm;
    ll lcmcnt = prefix/lcm;

    ll i = 0;
    ll money = 0;

    while(lcmcnt--){
        money += arr[i++] /100 * (x+y);
    }

    while(acnt--){
        money += arr[i++] / 100 * x;
    }

    while(bcnt--){
        money += arr[i++] / 100 * y;
    }

    return money >= k;
}

void solve(){
    ll n, k,a,x,y,b;
    cin>>n;

    vector<ll> arr(n);

    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater());

    cin>>x>>a>>y>>b>>k;
    if(x<y){
        swap(x,y);
        swap(a,b);
    }

    ll l=1;
    ll r=n;
    ll ans = -1;

    while(l<=r){
        ll mid = (l+r)/2;

        if(check(mid,arr,x,a,y,b,k)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}