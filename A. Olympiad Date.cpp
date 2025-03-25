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
        vector<int> vec(10);
        int ans = 0;
        bool flag = true;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            vec[x]++;
            if(vec[0] >= 3 && vec[1] >= 1 && vec[3] >= 1 && vec[2] >= 2 && vec[5] >= 1 && flag){
                ans = i+1;
                flag = false;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
