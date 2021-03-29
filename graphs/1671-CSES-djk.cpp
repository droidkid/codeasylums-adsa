#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

vector<vector<pii>> graph;
ll dist[100005];

int main() {
    int n, m;
    cin>>n>>m;

    for (int i=0; i<=n; i++) {
        graph.push_back(vector<pii>());
    }

    for (int i=0; i<m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(pii(v, w)); 
    }

    for (int i=1; i<=n; i++) {
        dist[i] = -1;
    }

    set<pii> pq;
    pq.insert(pii(0, 1)); // 0 is  cost. 1 is the node.

    dist[1] = 0;

    int cnt = 0;

    while (!pq.empty()) {
        // Let's expand the node on the 
        // current shortest path.

        // The first element of the  set
        // has the node with the shortest path.
        auto it = pq.begin();
        pq.erase(it); // Remove the element from the queue.

        // The shortest path we're currently exploring
        // ends at node 'u', and cost 'w' to reach there.
        int u = it->second;
        ll cost_so_far = it->first;

        // We've already reached 'u' sometime before.
        // So there's no need to expand it, because it's already expanded.
        if (dist[u] != -1 && dist[u] < cost_so_far) {
            continue;
        }

        cnt++;
        if (cnt == n) {
            break; // We've visited every node.
            // No point continuing.
        }

        // Let's expand 'u'
        for (auto edge: graph[u]) {
            int v = edge.first;
            ll w = edge.second;

            if (cost_so_far + w < dist[v] || dist[v] == -1) {
                pq.insert(pii(cost_so_far + w, v));
                dist[v] = cost_so_far + w;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
