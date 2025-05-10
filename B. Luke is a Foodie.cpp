#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while (t--)
    {
        int n,x;
        cin>>n>>x;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
        int cnt = 0;
        int l = arr[0]-x;
        int r = arr[0]+x;

        for(int i=1; i<n; i++){
            int low = arr[i]-x;
            int high = arr[i]+x;

            l = max(l,low);
            r = min(r,high);

            if(l>r){
                cnt++;
                l = low;
                r = high;                
            }

        }
        cout<<cnt<<"\n";
    }

    return 0;
}
