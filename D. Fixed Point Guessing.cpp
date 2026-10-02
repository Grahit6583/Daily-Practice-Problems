#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> query(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();

    vector<int> arr;
    for(int i=0; i<r-l+1; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    return arr;
}

void solve(){
    int n;
    cin>>n;

    int ans = 1;
    int l = 1;
    int r = n;

    while(l<=r){
        int mid = (l+r)/2;

        vector<int> a = query(l,mid);
        int cnt = 0;
        for(int x : a){
            if(x>=l && x<=mid){
                cnt++;
            }
        }

        if(cnt & 1){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    cout<<"! "<<ans<<endl;
    cout.flush();
    return;
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
