#include<bits/stdc++.h>

using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    long long inv = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
            inv += (mid - left + 1); // count inversions
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return inv;
}

long long mergeSort(vector<int>& arr, int low, int high) {
    long long inv = 0;
    if (low >= high) return inv;

    int mid = (low + high) / 2;

    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid + 1, high);
    inv += merge(arr, low, mid, high);

    return inv;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            mp[x].push_back(i);
        }
        for(int i=0; i<n; i++){
            int x;
            cin>>x;

            mp[x].push_back(i);
        }
        vector<int> arr(n);
        for(auto it : mp){
            arr[it.second[0]] = it.second[1];
        }
        cout<<mergeSort(arr,0,n-1)<<"\n";
    }

    return 0;
}