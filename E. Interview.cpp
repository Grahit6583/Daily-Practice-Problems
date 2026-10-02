#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int> piles(n);

    for(int i=0; i<n; i++){
        cin>>piles[i];
    }

    vector<int> prefix(n);
    prefix[0] = piles[0];

    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1]+piles[i];
    }

    int l=0;
    int r=n-1;

    while(l < r){
        int mid = (l+r)/2;

        int expected = prefix[mid] - (l==0 ? 0 : prefix[l-1]);

        int len = mid-l+1;

        cout<<"? "<<len<<" ";
        for(int i=l; i<=mid; i++){
            cout<<i+1<<" ";
        }
        cout<<endl;
        cout.flush();

        int actual;
        cin>>actual;

        if(actual > expected){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout<<"! "<<l+1<<endl;
    cout.flush();
    return ;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}