#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll cal_ans(int x, int y, int z){
    return 1LL*(x-y)*(x-y) + 1LL*(y-z)*(y-z) + 1LL*(z-x)*(z-x);
}

ll sol(vector<int> &a, vector<int> &b, vector<int> &c){
    int p1=0, p2=0, p3=0;
    ll ans = LLONG_MAX;
    while(p1<a.size()){
        while(p2<b.size()-1 && b[p2]<a[p1]){
            p2++;
        }
        
        while(p3<c.size()-1){
            if(c[p3+1]>a[p1]){
                break;
            }
            p3++;
        }
        
        ans = min(ans,cal_ans(a[p1],b[p2],c[p3]));
        p1++;
    }
    
    return ans;
}

void solve(){
    int nr,ng,nb;
    cin>>nr>>ng>>nb;
    
    vector<int> red(nr),green(ng),blue(nb);
    
    for(int i=0; i<nr; i++){
        cin>>red[i];
    }
    
    for(int i=0; i<ng; i++){
        cin>>green[i];
    }
    
    for(int i=0; i<nb; i++){
        cin>>blue[i];
    }
    
    
    sort(red.begin(),red.end());
    sort(green.begin(),green.end());
    sort(blue.begin(),blue.end());
    
    ll ans = cal_ans(red[0],green[0],blue[0]);
    
    ans = min(ans,sol(red,green,blue));
    ans = min(ans,sol(red,blue,green));
    ans = min(ans,sol(green,red,blue));
    ans = min(ans,sol(green,blue,red));
    ans = min(ans,sol(blue,red,green));
    ans = min(ans,sol(blue,green,red));
    
    cout<<ans<<"\n";
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
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}