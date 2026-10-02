#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n;
    cin>>n;

    vector<int> richer(n+1),poorer(n+1);

    for(int i=1; i<=n; i++){
        cin>>richer[i]>>poorer[i];
    }

    int l=1;
    int r=n+1;

    while(l+1<r){
        int mid = (l+r)/2;
        int takenpeople = 0;
        bool ok = false;

        //checker function
        for(int i=1; i<=n; i++){
            if(poorer[i] >= takenpeople && richer[i] >= mid - takenpeople - 1){
                takenpeople++;
            }
            if(takenpeople == mid){
                break;
            }
        }

        if(takenpeople == mid){
            ok = true;
        }

        if(ok){
            l=mid;
        }else{
            r=mid;
        }
    }

    cout<<l<<endl;
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