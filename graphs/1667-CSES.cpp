#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
// serves as a visited tracker.
// 0 indicates not visited.
// X - indicates visited from this node.
int prv[100005]; 

int main() {
    int n;
    int m;
    cin>>n>>m;

    // N nodes.
    // M edges.
    for (int i=0; i<=n; i++) {
        graph.push_back(vector<int>());
    }

    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        // Because undirected, add to both lists
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Visit every neighbour of U
        for (auto v: graph[u]) {
            // v is a neighbour of u.
            if (prv[v] != 0) continue; // This is already visited.
            // I am going to visit V coming from U
            prv[v] = u;
            q.push(v);
        }
    }

    if (prv[n] == 0) {
        // N was never visited.
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int> steps;
    steps.push_back(n);
    int cur = n;
    while (cur != 1) {
        // This is the retracing logic.
        cur = prv[cur];
        steps.push_back(cur);
    }

    cout<<steps.size()<<endl;
    reverse(steps.begin(), steps.end());
    for (auto u: steps) {
        cout<<u<<" ";
    }
    cout<<endl;
}