#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct person
{
    ll arrival;
    ll departure;
    ll index;
};


void solve(){
    ll n;
    cin>>n;

    vector<person> arr(n);
    vector<int> answer(n);
    set<pair<int,int>> rooms;

    for(int i=0; i<n; i++){
        cin>>arr[i].arrival>>arr[i].departure;
        arr[i].index = i;
    }
    
    sort(arr.begin(),arr.end(), [&](auto a, auto b){
        return a.arrival < b.arrival;
    });

    int counter = 0;
    for(auto Person : arr){
        int roomnumber;
        if(rooms.empty() || (*rooms.begin()).first > Person.arrival){
            roomnumber = ++counter;
        }else{
            roomnumber = (*rooms.begin()).second;
            rooms.erase(rooms.begin());
        }

        answer[Person.index] = roomnumber;
        rooms.insert({Person.departure + 1, roomnumber});
    }

    cout<<counter<<"\n";

    for(auto i : answer){
        cout<<i<<" ";
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}