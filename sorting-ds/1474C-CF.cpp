#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> v;
multiset<int> m;

int is_valid(int n, int x1, int p) {
    m.clear();
    for (int i=0; i<n-1; i++) {
        if (i==n || i==x1) continue;
        m.insert(v[i]);
    }

    if (p) {
        cout<<"YES"<<endl;
        cout<<v[n-1] + v[x1]<<endl;
        cout<<v[n-1]<<" "<<v[x1]<<endl;
    }

    int cur_sum = v[n-1];
    int cnt = 2;

    while (cnt < n) {
        auto e = m.end(); e--;
        int greatest = *e;
        m.erase(e);

        int left = cur_sum - greatest;
        auto it = m.find(left);
        if (it == m.end()) {
            return 0;
        }

        m.erase(it);
        if (p) {
            cout<<greatest<<" "<<left<<endl;
        }
        cur_sum = greatest;
        cnt = cnt + 2;
    }
    return 1;
}

void solve() {
    int n;
    cin>>n;
    n = 2 * n;
    v.clear();
    for (int i=0; i<n; i++) {
        int x; cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n-1; i++) {
        if (is_valid(n, i, 0)) {
            is_valid(n, i, 1);
            return;
        }

    }
    cout<<"NO"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}
