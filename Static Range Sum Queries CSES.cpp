#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> arr(n);
	vector<long long> pre(n);

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	pre[0] = arr[0];
	for(int i=1; i<n; i++){
		pre[i] = pre[i-1] + arr[i];
	}

	for(int i=0; i<q; i++){
		int l,r;
		cin>>l>>r;
		long long sum = pre[r-1] - (l-2 >= 0 ? pre[l-2] : 0);
		cout<<sum<<"\n";
	}

	return 0;
}