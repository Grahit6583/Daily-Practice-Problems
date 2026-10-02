#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    string s;
    cin>>s;

    if(n%2==1 || count(s.begin(),s.end(),'(') != count(s.begin(),s.end(),')')){
        cout<<"-1"<<"\n";
        return;
    }

    vector<int> ans(n);
    int cnt=0;
    int pos,neg;
    pos=1, neg=2;
    if(s[0] == ')'){
        pos=2,neg=1;
    }

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            cnt++;
            if(cnt > 0){
                ans[i]=pos;
            }else{
                ans[i]=neg;
            }
        }else{
            cnt--;
            if(cnt<0){
                ans[i] = neg;
            }else{
                ans[i] = pos;
            }
        }
    }

    if(*max_element(ans.begin(),ans.end()) == *min_element(ans.begin(),ans.end())){
        cout<<"1"<<"\n";
    }else{
        cout<<"2"<<"\n";
    }
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
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