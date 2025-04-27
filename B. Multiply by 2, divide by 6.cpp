#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int cnt_3=0;
        int cnt_2=0;

        while(n>0 && n%2 == 0){
            cnt_2++;
            n /= 2;
        }

        while(n>0 && n%3 == 0){
            cnt_3++;
            n /= 3;
        }

        if(n > 1 || cnt_2 > cnt_3){
            cout<<-1<<"\n";
        }
        else{
            cout<<(cnt_3-cnt_2)+cnt_3<<"\n";
        }
    }

    return 0;
}
