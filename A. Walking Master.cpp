#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int sx, sy, dx, dy;
        cin>>sx>>sy>>dx>>dy;

        if(sy > dy){
            cout<<-1<<"\n";
            continue;
        }

        int moves = (dy-sy);

        sx += moves;

        if(sx < dx){
            cout<<-1<<"\n";
            continue;
        }

        moves += (sx-dx);
        cout<<moves<<"\n";
    }

    return 0;
}
