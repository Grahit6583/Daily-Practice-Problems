#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int query(int x){
    cout<<"? "<<x<<endl;
    cout.flush();
    int val;
    cin>>val;
    return val;
}

void solve(){
    int n;
    cin>>n;

    int l=1;
    int r = n;
    int mid = 1;

    while(l<=r){
        mid = (l+r)/2;

        int a = mid-1 == 0 ? 1e9 : query(mid-1);
        int b = query(mid);
        int c = mid+1 == n+1 ? 1e9 : query(mid+1);

        if(a>b && c>b){
            break;
        }

        if(a>b){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout<<"! "<<mid<<endl;
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