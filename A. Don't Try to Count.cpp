#include<bits/stdc++.h>

using namespace std;

bool isSubstring(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {

            if (s1[i + j] != s2[j]) {
                break;
            }
        }

        if (j == m) {
            return true;
        }
    }
    
    return false;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        string x,s;
        cin>>x>>s;

        string temp = x;
        int k = max(n,m);
        k *= k;
        int cnt = 0;
        bool flag = false;
        if(isSubstring(x,s)){
            cout<<0<<"\n";
        }
        else{
            while(temp.size() <= k){
                if(isSubstring(temp,s)){
                    flag = true;
                    break;
                }
                cnt++;
                temp += temp;
            }
            if(flag){
                cout<<cnt<<"\n";
            }
            else{
                cout<<-1<<"\n";
            }
        }

    }

    return 0;
}
