#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	int n,x;
	cin>>n>>x;
	vector<int> arr(n);
	map<long long,long long> pre;

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	long long sum = 0;
	long long cnt = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
		cnt += pre[sum - x];
		if(sum == x){
			cnt++;
		}
		pre[sum]++;
	}
	cout<<cnt;
	return 0;
}