#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    unordered_map<string,int> mp;
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        if(mp.find(str) != mp.end()){
            cout<<str<<mp[str]<<"\n";
            mp[str]++;
        }
        else{
            cout<<"OK\n";
            mp[str]++;
        }
    }

    return 0;
}