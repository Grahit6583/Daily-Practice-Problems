#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int m;
        cin>>m;
        vector<vector<int>> arr(m);
        for(int i=0; i<m; i++){
            int n;
            cin>>n;
            for(int j=0; j<n; j++){
                int x;
                cin>>x;
                arr[i].push_back(x);
            }
            sort(arr[i].begin(),arr[i].end());
        }

        sort(arr.begin(),arr.end());
        vector<int> second(m);
        int mini = INT_MAX;
        for(int i=0; i<m; i++){
            mini = min(mini,arr[i][0]);
            second[i] = arr[i][1];
        }

        sort(second.begin(),second.end());
        long long sum = 0;
        for(int i=0; i<m; i++){
            if(i == 0){
                sum += mini;
                continue;
            }
            sum += second[i];
        }

        cout<<sum<<"\n";
    }

    return 0;
}
