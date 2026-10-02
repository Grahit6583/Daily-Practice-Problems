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

int right(int l,int r){
    int pivot = l-1;
    int ans = r;

    while(l<=r){
        int mid = (l+r)/2;
        if(query(pivot,mid) == pivot){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    return ans;
}

int left(int l,int r){
    int pivot = r+1;
    int ans = l;

    while(l<=r){
        int mid = (l+r)/2;
        if(query(mid,pivot)==pivot){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    return ans;
}


void solve(){
    int n;
    cin>>n;

    int pivot = query(1,n);

    if(pivot == 1){
        pivot = right(pivot+1,n);
    }else if(query(1,pivot) == pivot){
        pivot = left(1,pivot-1);
    }else{
        pivot = right(pivot+1,n);
    }

    cout<<"! "<<pivot<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}