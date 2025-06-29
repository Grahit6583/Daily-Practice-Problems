#include<bits/stdc++.h>

using namespace std;

void fun(string &s, string &ans, int i){
    if(i == s.size()){
        cout<<ans<<"\n";
        return ;
    }

    ans.push_back(s[i]);
    fun(s,ans,i+1);
    ans.pop_back();
    fun(s,ans,i+1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s = "abc";
    string t = "";
    fun(s,t,0);

    return 0;
}
