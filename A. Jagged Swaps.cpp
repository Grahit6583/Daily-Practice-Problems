#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        for(int i=0; i<n; i++){
            for(int j=1; j<n-1; j++){
                if(a[j-1] < a[j] && a[j+1] < a[j]){
                    swap(a[j],a[j+1]);
                }
            }
        }

        bool flag = true;
        for(int i=1; i<n; i++){
            if(a[i-1] > a[i]){
                flag = false;
            }
        }

        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
