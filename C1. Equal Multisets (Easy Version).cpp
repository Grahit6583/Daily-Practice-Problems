#include <bits/stdc++.h>
using namespace std;

string solve(int n, int k, vector<int> &a, vector<int> &b) {
    for (int i = k; i < n; i++) {
        if (b[i] != -1 && b[i] != a[i]) {
            return "NO";
        }
    }

    for (int i = k; i < n; i++) {
        if (b[i - k] != -1 && b[i - k] != a[i - k]) {
            return "NO";
        }
    }

    set<int> seen;
    for (int i = 0; i < k; i++) {
        if (b[i] != -1) {
            if (seen.count(b[i])) return "NO"; 
            seen.insert(b[i]);
        }
    }

    return "YES";
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin>> t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int> a(n),b(n);
	    
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    }
	    for(int i=0; i<n; i++){
	        cin>>b[i];
	    }
	    
	    cout<<solve(n,k,a,b)<<"\n";
	}
	return 0;
}
