#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    set<pair<int, int>> edges1, edges2;

    auto make_edge = [](int x, int y) {
        return make_pair(min(x, y), max(x, y));
    };

    edges1.insert(make_edge(a, b));
    edges1.insert(make_edge(b, c));
    edges1.insert(make_edge(c, a));

    edges2.insert(make_edge(d, e));
    edges2.insert(make_edge(e, f));
    edges2.insert(make_edge(f, d));

    int shared_edges = 0;
    for (auto edge : edges1) {
        if (edges2.count(edge)) {
            shared_edges++;
        }
    }

    int boundary_edges = 6 - (2 * shared_edges);
    cout << boundary_edges << endl;

    return 0;
}

