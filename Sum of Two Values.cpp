#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> vec(n);
    int i1 = -1;
    int i2 = -1;
    bool flag = false;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
        if(mp.find(k-vec[i]) != mp.end()){
            i1 = i;
            i2 = mp[k-vec[i]];
            flag = true;
            break;
        }
    
        mp[vec[i]] = i;
    }
    if(flag){
        cout<<i2+1<<" "<<i1+1<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE"<<"\n";
    }

    return 0;
}