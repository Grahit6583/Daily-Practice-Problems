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

        vector<int> vec(n,0);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        sort(vec.rbegin(),vec.rend());
        vector<int> ans;
        int pref = 0;
        for(int i=30; i>=0; i--){
            int next = -1;
            int l = 0;
            for(int j=0; j<n; j++){
                if ((vec[j] & (1 << i)) && ((pref & (1<<i)) == 0)) {
                    int curr = pref | vec[j];
                    if(curr > l){
                        next = j;
                        l = curr;
                    }
                }
            }
            if(next == -1){
                continue;
            }
            pref |= vec[next];
            ans.push_back(vec[next]);
            vec[next] = 0;
        }
        sort(vec.begin(),vec.end());
        for(int i=0; i<n; i++){
            if(vec[i] == 0){
                continue;
            }
            ans.push_back(vec[i]);
        }

        int l = ans.size();
        for(int i=0; i<l; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
