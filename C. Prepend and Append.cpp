#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string arr;
        cin>>arr;

        int i=0;
        int j=n-1;
        while(i<=j){
            if((arr[i]=='0' && arr[j]=='1') || (arr[i]=='1' && arr[j]=='0')){
                i++;
                j--;
            }
            else{
                break;
            }
        }
        cout<<(j-i+1)<<"\n";
    }

    return 0;
}
