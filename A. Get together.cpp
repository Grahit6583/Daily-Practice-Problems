#include<bits/stdc++.h>

using namespace std;

bool check(double time, vector<pair<double,double>> &people, int n){
    pair<double,double> curr = {-1e18,1e18};

    for(int i=0; i<n; i++){
        double x = people[i].first;
        double speed = people[i].second;
        pair<double,double> range = {x-speed*time , x+speed*time};
        curr = {max(curr.first,range.first),min(curr.second,range.second)};
        if(curr.first > curr.second){
            return false;
        }
    }

    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<double,double>> people(n);

    for(int i=0; i<n; i++){
        cin>>people[i].first>>people[i].second;
    }

    double l = 0;
    double r = 1e9;
    for(int iterations=0; iterations<60; iterations++){
        double mid = l + (r-l) / 2;
        if(check(mid,people,n)){
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << fixed << setprecision(7) << r << "\n";
    return 0;
}