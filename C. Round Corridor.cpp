#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,q;
    cin>>n>>m>>q;

    while(q--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        
        ll possible_common_walls = __gcd(n,m);

        ll g1 = -1;
        ll g2 = 0;

        if(x1 == 1 && x2==2){
            g1 = (y1-1)/(n/possible_common_walls)+1;
            g2 = (y2-1)/(m/possible_common_walls)+1;
        }
        else if(x1 == 2 && x2==1){
            g1 = (y1-1)/(m/possible_common_walls)+1;
            g2 = (y2-1)/(n/possible_common_walls)+1;
        }
        else if(x1 == x2 && x1 == 1){
            g1 = (y1-1)/(n/possible_common_walls)+1;
            g2 = (y2-1)/(n/possible_common_walls)+1;            
        }
        else if(x1 == x2 && x1 == 2){
            g1 = (y1-1)/(m/possible_common_walls)+1;
            g2 = (y2-1)/(m/possible_common_walls)+1;            
        }

        if(g1 == g2){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

}