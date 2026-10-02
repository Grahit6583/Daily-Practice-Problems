#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n,c;
    cin>>n>>c;

    string s;
    cin>>s;

    ll a=0;
    ll b=0;
    ll curr = 0;
    ll ans = 0;
    for(ll left=0, right=0; right<n; right++){
        a += (s[right]=='a');
        b += (s[right]=='b');
        if(s[right] == 'b'){
            curr += a;
        }

        while(curr > c){
            a -= (s[left]=='a');
            b -= (s[left]=='b');
            if(s[left] == 'a'){
                curr -= b;
            }
            left++;
        }

        ans = max(ans,right-left+1);
        
    }
    cout<<ans;
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