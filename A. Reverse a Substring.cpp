#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    string s;
    cin>>s;
    bool flag = false;
    int ind = -1;
    for(int i=0; i<n-1; i++){
        if(s[i] > s[i+1]){
            flag = true;
            ind = i;
            break;
        }
    }

    if(flag){
        cout<<"YES\n";
        cout<<ind+1<<" "<<ind+2<<"\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
