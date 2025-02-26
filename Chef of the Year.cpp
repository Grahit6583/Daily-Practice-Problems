#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    map<string,string> mp;
    for(int i=0; i<n; i++){
        string chef,country;
        cin>>chef>>country;
        mp[chef] = country;
    }

    map<string,int> chef, country;
    for(int i=0; i<m; i++){
        string x;
        cin>>x;

        chef[x]++;
        country[mp[x]]++;
    }

    string chef_ans;
    int maxi = INT_MIN;
    for(auto it : chef){
        if(it.second > maxi){
            chef_ans = it.first;
            maxi = it.second;
        }
    }

    maxi = INT_MIN;
    string country_ans;
    for(auto it : country){
        if(it.second > maxi){
            country_ans = it.first;
            maxi = it.second;
        }
    }
    cout<<country_ans<<"\n"<<chef_ans;
}