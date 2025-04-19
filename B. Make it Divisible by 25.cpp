#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int l = s.length();
        
        int op1 = 0;
        bool zero = false;
        int op2 = 0;
        bool five = false;
        for(int i=l-1; i>=0; i--){
            if(s[i] == '0'){
                op1 += (l-i-1);
                bool digit = false;
                int j = i-1;
                while(j >= 0){
                    if(s[j] == '0' || s[j] == '5'){
                        digit = true;
                        zero = true;
                        op1 += (i-j-1);
                        break;
                    }
                    j--;
                }
                if(digit){
                    break;
                }
            }
        }
        for(int i=l-1; i>=0; i--){
            if(s[i] == '5'){
                op2 += (l-i-1);
                bool digit = false;
                int j = i-1;
                while(j >= 0){
                    if(s[j] == '7' || s[j] == '2'){
                        digit = true;
                        five = true;
                        op2 += (i-j-1);
                        break;
                    }
                    j--;
                }
                if(digit){
                    break;
                }
            }
        }

        if(zero && (five == false)){
            cout<<op1<<"\n";
        }
        else if(five && (zero == false)){
            cout<<op2<<"\n";
        }
        else{
            cout<<min(op1,op2)<<"\n";
        }
    }

    return 0;
}
