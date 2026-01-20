#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    vector<int> vec(n,0);
    vector<long long> pref1(n,0);
    for(int i=0; i<n; i++){
        cin>>vec[i];
        if(i==0){
            pref1[i] = vec[i];
        }
        else{
            pref1[i] = pref1[i-1] + vec[i];
        }
    }

    vector<long long> pref2(n,0);
    sort(vec.begin(),vec.end());
    pref2[0] = vec[0];
    for(int i=1; i<n; i++){
        pref2[i] = pref2[i-1] + vec[i];
    }

    int q;
    cin>>q;
    while(q--){
        int t,l,r;
        cin>>t>>l>>r;

        long long ans = 0;
        if(t==1){
            ans = pref1[r-1] - (l-2 >= 0 ? pref1[l-2] : 0);
        }
        else{
            ans = pref2[r-1] - (l-2 >= 0 ? pref2[l-2] : 0);
        }

        cout<<ans<<"\n";
    }

    return 0;
}
