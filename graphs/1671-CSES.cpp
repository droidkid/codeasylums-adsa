/*
There are N nodes, M edges. 
Each edge is weighted.
*/

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> edges;
vector<ll> edge_weight;

ll dist[100005];

int main() {
    int n, m;
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(pii(u,v));
        edge_weight.push_back(w);
    }

    for (int i=2; i<=n; i++) {
        dist[i] = 1000000000000000LL;
    }
    dist[1] = 0;

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m; j++) {
            // We are now trying to see if we can
            // get a better solution using edge[j]
            int u = edges[j].first;
            int v = edges[j].second;
            ll w = edge_weight[j]; 

            // u, v, w
            // Is there a better solution using more
            // edges?
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }

        }
    }
    for (int i=1; i<=n; i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;

}