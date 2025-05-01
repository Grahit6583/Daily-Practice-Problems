#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n), b(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        for(int i=0; i<n; i++){
            cin>>b[i];
        }

        vector<long long> l_a(2*n+1,0);
        vector<long long> l_b(2*n+1,0);

        long long cnt = 1;
        for(int i=1; i<n; i++){
            if(a[i] == a[i-1]){
                cnt++;
            }
            else{
                l_a[a[i-1]] = max(l_a[a[i-1]],cnt);
                cnt=1;
            }
        }
        l_a[a[n-1]] = max(l_a[a[n-1]],cnt);
        cnt = 1;
        for(int i=1; i<n; i++){
            if(b[i] == b[i-1]){
                cnt++;
            }
            else{
                l_b[b[i-1]] = max(l_b[b[i-1]],cnt);
                cnt=1;
            }
        }
        l_b[b[n-1]] = max(l_b[b[n-1]],cnt);

        long long freq=-1;
        for(int i=1; i<=2*n; i++){
            freq = max(l_a[i]+l_b[i],freq);
        }

        cout<<freq<<"\n";
    }

    return 0;
}
