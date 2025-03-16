#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n,f,k;
        cin>>n>>f>>k;

        vector<int> a(n);
        int favorite = -1;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(f-1 == i){
                favorite = a[i];
            }
        }

        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int f_cnt = 0;
        int f_pos = -1;
        bool flag = true;
        for(int i=0; i<n; i++){
            if(a[i] == favorite){
                if(flag){
                    f_pos = i;
                    flag = false;
                }
                f_cnt = i;
            }
        }

        if(f_pos <= k-1 && f_cnt <= k-1){
            cout<<"YES\n";
        }
        else if(f_pos > k-1){
            cout<<"NO\n";
        }
        else{
            cout<<"MAYBE\n";
        }
    }

    return 0;
}
