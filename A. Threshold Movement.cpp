    #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define endl '\n'

    void solve(){
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        if(n%2){
            cout<<"No\n";
            return;
        }
        int mneven = INT_MAX;
        int mxodd = 0;

        for(int i=0; i<n; i++){
            if(i%2){
                mxodd = max(mxodd,arr[i]);
            }else{
                mneven = min(mneven,arr[i]);
            }
        }


        if(mxodd+1 < mneven){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }

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