#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    ll n, t, a, b;
    cin >> n >> t >> a >> b;

    vector<ll> hard(n);
    ll cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> hard[i];
        if (hard[i])
        {
            cnt1++;
        }
        else
        {
            cnt0++;
        }
    }

    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = {x, hard[i]};
    }

    arr.push_back({t + 1, 0});

    sort(arr.begin(), arr.end());

    ll cnta = 0, cntb = 0;
    ll ans = 0;

    for (int i = 0; i <= n; i++)
    {
        ll need = cnta * a + cntb * b;
        ll has = arr[i].first - 1 - need;

        if (has >= 0)
        {
            ll cana = min((cnt0 - cnta), has / a);
            has -= cana * a;
            ll canb = min((cnt1 - cntb), has / b);
            ans = max(ans, cnta + cntb + cana + canb);
        }
        int l = i;
        while (l < arr.size() && arr[l].first == arr[i].first)
        {
            if (arr[l].second)
            {
                cntb++;
            }
            else
            {
                cnta++;
            }
            l++;
        }
        i = l - 1;
    }

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}