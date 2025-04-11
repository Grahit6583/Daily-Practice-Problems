#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long wheels;
        cin>>wheels;
        if(wheels < 4 || wheels % 2 == 1){
            cout<<-1<<"\n";
        }
        else{
            long long mini = (wheels+5)/6;
            long long maxi = wheels/4;
            cout<<mini<<" "<<maxi<<"\n";
        }
    }

    return 0;
}
