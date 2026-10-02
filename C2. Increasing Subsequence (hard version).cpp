#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int i=0;
    int j=n-1;
    string s = "";
    int last = 0;
    while(i<=j){
        if(arr[i] < arr[j]){
            if(arr[i] > last){
                last = arr[i];
                s += 'L';
                i++;
            }else if(arr[j] > last){
                last = arr[j];
                s += 'R';
                j--;
            }else{
                break;
            }
        }else if(arr[i] > arr[j]){
            if(arr[j] > last){
                last = arr[j];
                s += 'R';
                j--;
            }else if(arr[i] > last){
                last = arr[i];
                s += 'L';
                i++;
            }else{
                break;
            }            
        }else {
            if(arr[i] <= last) break;
            int left = i+1;
            int right = j-1;
            while (left <= j && arr[left] > arr[left-1])
            {
                left++;
            }
            while(right >= i && arr[right] > arr[right+1]){
                right--;
            }
            if((left - i) >= (j-right)){
                s += string((left-i),'L');
            }else{
                s += string((j-right),'R');
            }
            break;
        }
    }

    cout<<s.size()<<"\n"<<s<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}