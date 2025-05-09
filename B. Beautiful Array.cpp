#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        long long n,k,b,s;
        cin>>n>>k>>b>>s;

        long long mini_s = b*k;
        long long maxi_s = (b*k)+(k-1)*n;

        if(s < mini_s || s > maxi_s){
            cout<<-1<<"\n";
        }
        else{
            vector<long long> arr(n,0);
            arr[0] = mini_s;
            s -= mini_s;
            for(int i=0; i<n; i++){
                long long add = min(s,k-1);
                arr[i] += add;
                s -= add;
            }

            for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
