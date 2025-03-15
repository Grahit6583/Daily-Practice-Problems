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

        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }

        int maxi = *max_element(vec.begin(),vec.end());

        vector<int> b,c;
        for(int i=0; i<n; i++){
            if(vec[i] != maxi){
                b.push_back(vec[i]);
            }
            else{
                c.push_back(vec[i]);
            }
        }

        if(c.size() == 0 || b.size() == 0){
            cout<<-1<<"\n";
        }
        else{
            int l = c.size();
            int k = b.size();
            cout<<k<<" "<<l<<"\n";
            for(int i=0; i<k; i++){
                cout<<b[i]<<" ";
            }
            cout<<"\n";
            for(int i=0; i<l; i++){
                cout<<c[i]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
