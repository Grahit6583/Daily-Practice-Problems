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

        map<int,int> mp;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            mp[x]++;
        }

        if(mp.size() >= 3){
            cout<<"NO\n";
        }
        else{
            long long freq1 = mp.begin()->second;
            long long freq2 = mp.rbegin()->second;

            if(n%2 == 1 && abs(freq1-freq2) == 1){
                cout<<"YES\n";
            }
            else if(freq1 == freq2){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}
