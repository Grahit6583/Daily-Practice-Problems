#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class MedianContainer{
    private:
        multiset<ll> left;
        multiset<ll> right;
        int k;

    public:
        MedianContainer(int k){
            this->k = k;
        }
        void balance(){
            if(left.size() < k && !right.empty()){
                left.insert(*right.begin());
                right.erase(right.begin());
            }else if(left.size() > k && !left.empty()){
                right.insert(*left.rbegin());
                left.erase(prev(left.end()));
            }
        }

        void insert(ll x){
            if(left.empty() || x <= *left.rbegin()){
                left.insert(x);
            }else{
                right.insert(x);
            }
            balance();
        }

        void remove(ll x){
            auto it = left.find(x);
            if(it != left.end()){
                left.erase(it); // Fast erase using iterator
            } else {
                auto it_right = right.find(x);
                if (it_right != right.end()) {
                    right.erase(it_right);
                }
            }
            balance();
        }

        ll median(){
            return *left.rbegin();
        }
};

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<ll> ans;
    int windowSize = (k+1)/2;
    MedianContainer container(windowSize);

    for(int i=0; i<k; i++){
        container.insert(arr[i]);
    }

    ans.push_back(container.median());

    for(int i=k; i<n; i++){
        container.remove(arr[i-k]);
        container.insert(arr[i]);
        ans.push_back(container.median());
    }

    for(int i=0; i<n-k+1; i++){
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

    while(t--){
        solve();
    }

    return 0;
}