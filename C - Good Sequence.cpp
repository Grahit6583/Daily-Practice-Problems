#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        mp[k]++;
    }

    int item = 0;

    for(auto it : mp){
        if(it.second < it.first){
            item += it.second;
        }
        else if(it.second > it.first){
            item += (it.second - it.first);
        }
    }

    cout<<item<<"\n";
}