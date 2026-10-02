#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    string s;
    cin>>s;

    int k;
    cin>>k;
    int n = s.size();
    deque<int> nums[10];

    for(int i=0; i<n; i++){
        nums[s[i]-'0'].push_back(i);
    }
    string t;
    for(int i=0; i<n; i++){
        int currIdx = s.size();
        int newIdx = s.size();

        for(int j=0; j<10; j++){
            if(nums[j].size()){
                currIdx = min(currIdx,nums[j].front());
            }
        }

        for(int j=(i==0); j<10; j++){
            if(nums[j].size() && nums[j].front()-currIdx <= k){
                t += ('0'+j);
                newIdx = nums[j].front();
                break;
            }
        }

        k -= newIdx - currIdx;
        for(int j=0; j<10; j++){
            while (nums[j].size() && nums[j].front() <= newIdx)
            {
                nums[j].pop_front();
            }
        }
    }

    cout<<string(t.begin(),t.end()-k)<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}