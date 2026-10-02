#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &arr, int n, int mini){
        multiset<int> st;
        for(int i=0; i<n; i++){
            if(arr[i]%mini == 0){
                st.insert(arr[i]);
            }
        }

        for(int i=0; i<n; i++){
            if(arr[i]%mini == 0){
                int temp = *st.begin();
                arr[i] = temp;
                st.erase(st.find(temp));
            }
        }

        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n,0);
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            mini = min(mini,arr[i]);
        }

        solve(arr,n,mini);
    }
}