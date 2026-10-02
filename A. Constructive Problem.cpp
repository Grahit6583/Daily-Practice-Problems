#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        map<int,int> mp;

        for(int i=0; i<n; i++){
            cin>>a[i];
            mp[a[i]]++;
        }


        int mex = 0;

        for(auto it : mp){
            if(it.first == mex){
                mex++;
            }
            else{
                break;
            }
        }

        int target_mex = mex + 1;

        int l = -1;
        int r = -1;

        for(int i=0; i<n; i++){
            if(a[i] == target_mex){
                if(l == -1){
                    l = i;
                }
                r = i;
            }
        }

        if(l != -1){
            for(int i=l; i<=r; i++){
                a[i] = mex;
            }

            map<int,int> freq;

            for(int i=0; i<n; i++){
                freq[a[i]]++;
            }

            int newMex = 0;

            for(auto it : freq){
                if(it.first == newMex){
                    newMex++;
                }
                else{
                    break;
                }
            }

            if(newMex == target_mex){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            int flag = 0;
            for(auto it : mp){
                if(it.first < mex && it.second > 1){
                    flag = 1;
                }
                if(it.first > mex+1){
                    flag = 1;
                }
            }

            if(flag) cout<<"YeS\n";
            else cout<<"nO000\n";
        }
    }

    return 0;
}
