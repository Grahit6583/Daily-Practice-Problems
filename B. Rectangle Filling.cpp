#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int m,n;
    cin>>m>>n;

    vector<string> vec(m);

    for(int i=0; i<m; i++){
        cin>>vec[i];
    }

    if(vec[0][0] == vec[m-1][n-1] || vec[0][n-1] == vec[m-1][0]){
        cout<<"Yes"<<"\n";
    }
    else{
        
    }

    return 0;
}
