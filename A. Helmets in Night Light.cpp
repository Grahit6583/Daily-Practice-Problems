#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,p;
        cin>>n>>p;

        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            cin>>b[i];
        }

        vector<pair<long long,long long>> cost_cap(n+1);
        cost_cap[0] = {p,n+1};
        for(int i=0; i<n; i++){
            cost_cap[i+1] = {b[i],a[i]};
        }

        sort(cost_cap.begin(),cost_cap.end());

        int total = 1;
        long long cost = p;
        int i = 0;

        while(total < n){
            int left = n-total;
            if(cost_cap[i].second <= left){
                total += cost_cap[i].second;
                cost = cost + (cost_cap[i].first * cost_cap[i].second);
            }
            else{
                total = n;
                cost += (left* 1LL * cost_cap[i].first);
            }
            i++;
        }

        cout<<cost<<"\n";
    }

    return 0;
}
