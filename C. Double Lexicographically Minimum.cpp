#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(){
    string s;
    cin>>s;

    int n = s.size();
    sort(s.begin(),s.end());

    vector<char> anschar(n);

    int left = 0;
    int right = n-1;

    for(int i=0; i<n; i+=2){
        if(i == n-1){
            anschar[left] = s[i];
        }else if(s[i] == s[i+1]){
            anschar[left] = s[i];
            anschar[right] = s[i];
            left++;
            right--;
        }else{
            if(s[i+1] == s[n-1]){
                int len = n-i-1;
                int firsthalf = ceil(len/2.0);
                int secondhalf = len-firsthalf;
                while(firsthalf--){
                    anschar[left] = s[i+1];
                    left++;
                }
                anschar[left] = s[i];
                while(secondhalf--){
                    anschar[right] = s[i+1];
                    right--;
                }
                break;
            }else{
                for(int j=i+1; j<n; j++){
                    anschar[left] = s[j];
                    left++;
                }
                anschar[right] = s[i];
                break;
            }
        }
    }

    string ans = "";
    for(char ch : anschar){
        ans += ch;
    }

    cout<<ans<<"\n";
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
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}