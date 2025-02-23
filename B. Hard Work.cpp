#include<bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string a,b,c;
    cin>>a>>b>>c;

    string s,t,u;
    for(char c : a){
        if(c == ';' || c == '-' || c == '_'){
            continue;
        }
        s += tolower(c);
    }
    for(char c : b){
        if(c == ';' || c == '-' || c == '_'){
            continue;
        }
        t += tolower(c);
    }
    for(char z : c){
        if(z == ';' || z == '-' || z == '_'){
            continue;
        }
        u += tolower(z);
    }

    set<string> st;
    string temp = s+t+u;
    st.insert(temp);
    temp = s+u+t;
    st.insert(temp);
    temp = t+s+u;
    st.insert(temp);
    temp = t+u+s;
    st.insert(temp);
    temp = u+s+t;
    st.insert(temp);
    temp = u+t+s;
    st.insert(temp);

    int len = s.length() + t.length() + u.length();
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string std;
        cin>>std;

        string temp = "";
        for(char z : std){
            if(z == ';' || z == '-' || z == '_'){
                continue;
            }
            temp += tolower(z);
        }

        transform(std.begin(), std.end(), std.begin(), ::tolower);

        if(st.count(temp)){
            cout<<"ACC\n";
        }
        else{
            cout<<"WA\n";
        }
    }

    return 0;
}

// rr
// rrx
// ab
// 1
// rabrrrx