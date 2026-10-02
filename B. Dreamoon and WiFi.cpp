#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

double waysToChoosePluses(ll n, ll r) {
    if (r < 0 || r > n) return 0;

    if (r > n - r)
        r = n - r;

    double ans = 1;

    for (ll i = 1; i <= r; i++) {
        ans *= (n - r + i);
        ans /= i;
    }

    return ans;
}

double totalPossibleAssignments(ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }

    return res;
}

void solve(){
    string commandDrazilSend, commandPhoneRecog;

    cin>>commandDrazilSend;
    cin>>commandPhoneRecog;

    int n = commandDrazilSend.length();

    ll finalPosition = 0;
    ll positionByignoringUnrecogCommand = 0;
    ll unRecogCommand = 0;

    for(int i=0; i<n; i++){
        finalPosition += (commandDrazilSend[i] == '+' ? 1 : -1);

        if(commandPhoneRecog[i] == '+'){
            positionByignoringUnrecogCommand += 1;
        }else if(commandPhoneRecog[i] == '-'){
            positionByignoringUnrecogCommand -= 1;
        }else{
            unRecogCommand++;
        }
    }

    ll diff = finalPosition - positionByignoringUnrecogCommand + unRecogCommand;

    if (diff & 1) {
        cout << fixed << setprecision(12) << 0.0 << '\n';
        return;
    }

    ll requiredPlus = diff / 2;

    if (requiredPlus < 0 || requiredPlus > unRecogCommand) {
        cout << fixed << setprecision(12) << 0.0 << '\n';
        return;
    }

    double ways = waysToChoosePluses(unRecogCommand,requiredPlus);
    double assignments = totalPossibleAssignments(2,unRecogCommand);

    double probability = ways/assignments;

    cout << fixed << setprecision(12) << probability << '\n';

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