#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        long long a[n];
        for(int i=0; i<n-1; i++){
            cin>>a[i];
        }

        long long sum = 0;
        for(int i=0; i<n-1; i++){
            sum += a[i];
        }

        cout<<-1 * sum<<"\n";
    }

    return 0;
}
