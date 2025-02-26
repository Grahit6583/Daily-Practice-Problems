#include<bits/stdc++.h>

using namespace std;

int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
    string s;
    cin>>s;

    int n = s.size();
    vector<int> vec(26,0);

    for(int i=0; i<n; i++){
        vec[s[i]-'A']++;
    }

    int odd_cnt = 0;
    for(int i=0; i<26; i++){
        if(vec[i]%2 == 1){
            odd_cnt ++;
            if(odd_cnt > 1){
                cout<<"NO SOLUTION";
                return 0;
            }
        }
    }

    string mid;
    string front;
    string rear;
    for(int i=0; i<26; i++){

        char ch = i + 'A';
        if(vec[i]%2 == 1){
            for(int j=0; j<vec[i]; j++){
                mid += ch;
            }
        }
        else{
            for(int j=0; j<vec[i]/2; j++){
                front.push_back(ch);
                rear.push_back(ch);
            }
        }
    }
    reverse(rear.begin(),rear.end());
    cout<<front<<mid<<rear<<"\n";
}