#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;


    string s;
    cin>>s;

    vector<int> zeros;

    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            zeros.push_back(i+1);
        }
    }

    int i=0;
    int j=k;
    int z=0;
    int mn = INT_MAX;

    while(j<(int)zeros.size()){
        while(max(zeros[z]-zeros[i],zeros[j]-zeros[z])>max(zeros[z+1]-zeros[i],zeros[j]-zeros[z+1])){
            z++;
        }

        int m = max(zeros[z]-zeros[i],zeros[j]-zeros[z]);
        mn = min(mn,m);
        i++;
        j++;
    }
    cout<<mn;
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