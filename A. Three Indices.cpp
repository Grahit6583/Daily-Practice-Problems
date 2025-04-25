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
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int a=-1,b=-1,c=-1;

        for(int i=0; i<n-1; i++){
            if(arr[i] < arr[i+1]){
                a=i;
                b=i+1;
                int k=i+2;
                bool flag = false;
                while(k<n){
                    if(arr[i+1] > arr[k]){
                        c=k;
                        flag = true;
                        break;
                    }
                    k++;
                }
                if(flag){
                    break;
                }
            }
        }

        if(a==-1 || b==-1 || c==-1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cout<<a+1<<" "<<b+1<<" "<<c+1<<"\n";
        }
    }

    return 0;
}
