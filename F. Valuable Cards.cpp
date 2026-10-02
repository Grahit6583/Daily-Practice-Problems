#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'


void solve() {
    int n,x;
    cin>>n>>x;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    set<int> current,factors;

    for(int i=1; i*i<=x; i++){
        if(x%i == 0){
            factors.insert(i);
            factors.insert(x/i);
        }
    }

    current.insert(1);
    int seg = 1;
    for(int i=0; i<n; i++){
        set<int> newinserts;
        newinserts.insert(arr[i]);

        for(auto j :factors){
            if(j%arr[i] == 0 && current.count(j/arr[i])){
                newinserts.insert(j);
            }
        }

        if(newinserts.count(x)){
            seg++;
            current.clear();
            current.insert(arr[i]);
            current.insert(1);
        }else{
            for(auto it : newinserts){
                current.insert(it);
            }
        }
    }

    cout<<seg<<"\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}