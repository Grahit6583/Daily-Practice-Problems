#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int query(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    int x;
    cin>>x;

    return x;
}

void solve(){
    set<int> arr = {4,8,15,16,23,42};

    int ab,ac,ad,ae;

    ab = query(1,2);
    ac = query(1,3);
    ad = query(1,4);
    ae = query(1,5);

    pair<int,int> ff, ss;

    for(auto it : arr){
        if(ab%it == 0 && arr.find(ab/it) != arr.end()){
            ff.first = it;
            ff.second = ab/it;
        }
        if(ac%it == 0 && arr.find(ac/it) != arr.end()){
            ss.first = it;
            ss.second = ac/it;
        }
    }

    vector<int> ans(6);

    if(ff.first == ss.first || ff.first == ss.second){
        ans[0] = ff.first;
    }else{
        ans[0] = ff.second;
    }

    ans[1] = ab/ans[0];
    ans[2] = ac/ans[0];
    ans[3] = ad/ans[0];
    ans[4] = ae/ans[0];

    for(int i=0; i<6; i++){
        if(arr.find(ans[i]) != arr.end()){
            arr.erase(ans[i]);
        }
    }
    ans[5] = *arr.begin();

    cout<<"! ";
    for(int i=0; i<6; i++){
        cout<<ans[i]<<" ";
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

    int t=1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}