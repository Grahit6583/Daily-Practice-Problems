#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    int mini = INT_MAX;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        if(x < 0){
            mini = min(mini, -1 * x);
        }
        else if(x == 0){
            mini = 0;
            break;
        }
        else{
            mini = min(mini,x);
        }
    }
    cout<<mini<<"\n";
    return 0;
}
