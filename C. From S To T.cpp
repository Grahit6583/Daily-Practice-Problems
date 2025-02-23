#include<bits/stdc++.h>

using namespace std;
bool isSubSeq(string& s1, string& s2)
{
    int m = s1.length(), n = s2.length();
    if (m > n) return false;
  
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == m;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int q;
    cin>>q;
    while(q--){
        string s,t,p;
        cin>>s>>t>>p;

        int m = t.size();
        int n = s.size();
        int o = p.size();

        unordered_map<char,int> mp_t;
        unordered_map<char,int> st;

        for(int i=0; i<m; i++){
            mp_t[t[i]]++;
        }

        for(int i=0; i<n; i++){
            st[s[i]]++;
        }

        for(int i=0; i<o; i++){
            st[p[i]]++;
        }
        
        bool flag = false;
        for(auto it : mp_t){
            if(st.find(it.first) != st.end() && st[it.first] >= it.second){
                flag = true;
            }
            else{
                flag = false;
                break;
            }
        }

        if(flag == false){
            cout<<"NO\n";
        }
        else{
            flag = isSubSeq(s,t);
            if(flag){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

    }

    return 0;
}