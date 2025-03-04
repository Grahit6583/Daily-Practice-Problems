#include<bits/stdc++.h>

using namespace std;

class mp{
    public:
        long long data;
        int index;
        mp(){
            data = LLONG_MIN;
            index = -1;
        }

        bool operator<(const mp& other) const {
            // Define how to compare based on your criteria
            return data < other.data;  // Example: comparing based on 'data'
        }
};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<mp> arr1(n), arr2(n), arr3(n);
        for(int i=0; i<n; i++){
            cin>>arr1[i].data;
            arr1[i].index = i;
        }

        for(int i=0; i<n; i++){
            cin>>arr2[i].data;
            arr2[i].index = i;
        }

        for(int i=0; i<n; i++){
            cin>>arr3[i].data;
            arr3[i].index = i;
        }

        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        sort(arr3.begin(),arr3.end());
        
        long long sum = 0;
        for(int i=3; i>=1; i--){
            for(int j=3; j>=1; j--){
                for(int k=3; k>=1; k--){
                    if(arr1[n-i].index != arr2[n-j].index && arr2[n-j].index != arr3[n-k].index && arr1[n-i].index != arr3[n-k].index){
                        sum = max(sum, (arr1[n-i].data+arr2[n-j].data+arr3[n-k].data));
                    }
                }
            }
        }

        cout<<sum<<"\n";
    }

    return 0;
}