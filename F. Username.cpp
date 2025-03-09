#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    string first, last;
    cin>>first>>last;

    int i=1;
    string ans = "";
    ans += first[0];

    int n = first.size();
    int m = last.size();

    while(i<n && first[i] < last[0]){
        ans += first[i];
        i++;

    }
    ans += last[0];

    cout<<ans;

    return 0;
}
