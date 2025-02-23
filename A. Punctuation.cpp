#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;
    getline(cin,s);

    stringstream ss(s);

    string word;
    string str;

    while(ss >> word){
        str += (word + " ");
    }

    return 0;
}