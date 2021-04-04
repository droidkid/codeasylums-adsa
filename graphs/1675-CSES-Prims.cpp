#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<ll,ll> pii;

// Stores weight, (u,v)
typedef pair<ll, pii> edge;

vector<vector<pii>> graph;

// If 1, this node is part of the active set.
int is_active[100005];

int main() {
    int n, m;
    cin>>n>>m;
    graph.resize(n+1);

    for (int i=0; i<m; i++) {
        ll u, v, w;
        cin>>u>>v>>w;

        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
    }

    priority_queue<edge, vector<edge>, greater<edge>> pq;

    // Let's add 1 to the active set.
    is_active[1] = 1;
    for (auto e: graph[1]) {
        ll v = e.first;
        ll w = e.second; 

        // Now add this to the pq;
        pq.push(edge(w, pii(1, v)));
    }

    ll ans = 0;
    ll node_count = 1; // Because we've already taken 1.

    // Expand the least edge always.
    while (!pq.empty()) {

        // Pop out the edge with the smallest weight.
        auto it = pq.top();
        pq.pop();

        ll w = it.first;
        ll u = it.second.first;
        ll v = it.second.second;

        if (is_active[u] && is_active[v]) {
            // This edge is combining two nodes
            // already part of the active set.
            // This edge is making a cycle.
            continue;
        }

        // Make v the new node to add.
        if (is_active[v]) swap(u, v);

        is_active[v] = 1;
        ans = ans + w;
        node_count++;
        for (auto e: graph[v]) {
            ll nv = e.first;
            ll nw = e.second; 

            // Now add this to the pq;
            pq.push(edge(nw, pii(v, nv)));
        }
    }

    if (node_count != n) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        cout<<ans<<endl;
    }

}