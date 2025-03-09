#include <bits/stdc++.h>
using namespace std;

class SegT {
public:
    int n;
    vector<int> t;
    
    SegT(const vector<int>& bs) {
        n = bs.size();
        t.resize(4 * n);
        build(bs, 0, n - 1, 0);
    }
    
    void build(const vector<int>& bs, int s, int e, int i) {
        if(s == e) {
            t[i] = bs[s];
            return;
        }
        int m = (s + e) / 2;
        build(bs, s, m, 2 * i + 1);
        build(bs, m + 1, e, 2 * i + 2);
        t[i] = max(t[2 * i + 1], t[2 * i + 2]);
    }
    
    void upd(int pos, int val, int s, int e, int i) {
        if(s == e) {
            t[i] = val;
            return;
        }
        int m = (s + e) / 2;
        if(pos <= m)
            upd(pos, val, s, m, 2 * i + 1);
        else
            upd(pos, val, m + 1, e, 2 * i + 2);
        t[i] = max(t[2 * i + 1], t[2 * i + 2]);
    }
    
    int qry(int tgt, int s, int e, int i) {
        if(t[i] < tgt)
            return -1;
        if(s == e)
            return s;
        int m = (s + e) / 2;
        int l = qry(tgt, s, m, 2 * i + 1);
        if(l != -1)
            return l;
        return qry(tgt, m + 1, e, 2 * i + 2);
    }
    
    int qry(int tgt) {
        return qry(tgt, 0, n - 1, 0);
    }
};

int unplaced(vector<int>& fr, vector<int>& bs) {
    int n = fr.size();
    SegT st(bs);
    int placed = 0;
    
    for (int i = 0; i < n; i++) {
        int idx = st.qry(fr[i]);
        if(idx != -1) {
            placed++;
            st.upd(idx, -1, 0, st.n - 1, 0);
        }
    }
    
    return n - placed;
}

int main() {
    vector<int> fr = {4, 2, 5};
    vector<int> bs = {3, 5, 4};
    cout << unplaced(fr, bs) << endl; // Expected output: 1
    return 0;
}
