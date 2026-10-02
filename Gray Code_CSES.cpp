#include<bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    
    vector<string> arr = {"0","1"};

    for(int i=2; i<=n; i++){
        int e = arr.size()-1;
        while(e >= 0){
            arr.push_back(arr[e]);
            e--;
        }

        int cnt = pow(2,i);

        for(int j=1; j<=cnt; j++){
            if(j<=(cnt/2)){
                arr[j-1] = "0" + arr[j-1];  
            }
            else{
                arr[j-1] = "1" + arr[j-1];
            }
        }
    }

    for(auto i : arr){
        cout<<i<<"\n";
    }

    return 0;
}