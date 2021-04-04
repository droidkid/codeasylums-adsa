#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// For each node, store it's parent.
// if dsu[u] == u, then u is a leader.
// leader basically represents a component.

// DSU START

int dsu[100005]; 

void initialize_dsu() {
    for (int i=0; i < 100005; i++) {
        // Every node is it's own leader
        // Everything is separate at the start.
        dsu[i] = i;
    }
}

int find_leader(int u) {
    if (dsu[u] != u) {
        int leader = find_leader(dsu[u]);
        // Flatten the tree, this is the magic.
        dsu[u] = leader;
    }
    return dsu[u];
}

void merge(int u, int v) {
    int u_leader = find_leader(u);
    int v_leader = find_leader(v);
    // Now u_leader is not a leader.
    dsu[u_leader] = v_leader;
}

// DSU END

typedef long long ll;
typedef pair<ll,ll> pii;

// Stores weight, (u,v)
typedef pair<ll, pii> edge;

vector<edge> edge_list;

int main() {
    initialize_dsu();

    int n, m;
    cin>>n>>m;

    for (int i=0; i<m; i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        edge_list.push_back(edge(w, pii(u, v)));
    }

    // Now Kruskal's begins.
    sort(edge_list.begin(), edge_list.end());

    ll ans = 0; // ans is the total weight of edges selected.
    ll edge_count = 0;

    for (auto e: edge_list) {
        ll edge_weight = e.first;
        ll u = e.second.first;
        ll v = e.second.second;

        if (find_leader(u) == find_leader(v)) {
            // u and v are already connected.
            continue;
        }

        // We've selected this edge.
        merge(u, v);
        ans = ans + edge_weight;
        edge_count++;
    }

    if (edge_count != n-1) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        cout<<ans<<endl;
    }
}