#include<bits/stdc++.h>
using namespace std;

#define ll long long

class MedianContainer{
    private:
        ll sumLeft,sumRight;
        multiset<ll> left, right;
    public:
        MedianContainer(){
            sumLeft = 0;
            sumRight = 0;
        }

        void adjust(){
            if(left.size() && right.size() && *right.begin() < *left.rbegin()){
                ll leftLast = *left.rbegin();
                ll rightFirst = *right.begin();

                sumLeft -= leftLast, sumRight -= rightFirst;
                sumLeft += rightFirst, sumRight += leftLast;
                left.extract(leftLast), right.extract(rightFirst);
                left.insert(rightFirst), right.insert(leftLast);
            }

            if(left.size() > right.size() + 1) {
                sumLeft -= *left.rbegin();
                sumRight += *left.rbegin();
                right.insert(*left.rbegin());
                left.extract(*left.rbegin());
            }
            else if(right.size() > left.size()) {
                sumLeft += *right.begin();
                sumRight -= *right.begin();
                left.insert(*right.begin());
                right.extract(*right.begin());
            }

        }

        void insert(ll x){
            right.insert(x);
            sumRight += x;
            adjust();
        }

        void remove(ll x){
            if(right.count(x)){
                sumRight -= x;
                right.extract(x); 
            }else{
                sumLeft -= x;
                left.extract(x);
            }

            adjust();
        }

        ll cost(){
            return ((1ll * left.size() * (*left.rbegin())-sumLeft) + (sumRight - (1ll * right.size() * (*left.rbegin()))));
        }
};

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<ll> arr(n);

    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    MedianContainer container;

    for(ll i=0; i<k; i++){
        container.insert(arr[i]);
    }

    cout<<container.cost()<<" ";

    for(ll i=k; i<n; i++){
        container.remove(arr[i-k]);
        container.insert(arr[i]);
        cout<<container.cost()<<" ";
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

    ll t=1;
    while(t--){
        solve();
    }

    return 0;
}