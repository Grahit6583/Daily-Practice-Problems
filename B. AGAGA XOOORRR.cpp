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

        int x = 0;
        vector<int> a(n,0);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            x ^= a[i];
        }

        if (x == 0 || n % 2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
