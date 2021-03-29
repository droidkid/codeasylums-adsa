#include <iostream>
#include <vector>
using namespace std;

// For each node, store it's children.
vector<vector<int>> tree;
int count[200005];

void solve(int u) {
    for (auto v: tree[u]) {
        solve(v);
        count[u] += (count[v] + 1); 
    }
}


int main() {
    int n;
    cin>>n;

    for (int i=0; i<=n; i++) {
        tree.push_back(vector<int>());
    }

    // In this problem, 
    // 1 is assumed to be the root.
    for (int u=2; u<=n; u++) {
        int v; cin>>v;

        // U's parent is V
        // We're storing this as a directed tree.
        tree[v].push_back(u);
    }

    // Start counting at our root.
    solve(1);

    for (int i=1; i<=n; i++) {
        cout<<count[i]<<" ";
    }
    cout<<endl;
}