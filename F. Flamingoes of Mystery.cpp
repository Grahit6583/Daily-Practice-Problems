#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    cout.flush();

    int x;
    cin >> x;

    return x;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pref(n + 1);
    vector<int> ans(n + 1);

    for(int i = 2; i <= n; i++){
        pref[i] = ask(1, i);
    }

    int suf = ask(2, n);

    ans[1] = pref[n] - suf;

    ans[2] = pref[2] - ans[1];

    for(int i = 3; i <= n; i++){
        ans[i] = pref[i] - pref[i - 1];
    }

    cout << "! ";

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
    cout.flush();

    return 0;
}