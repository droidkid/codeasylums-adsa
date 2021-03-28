#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> graph;
int is_storage[100005];

int main() {
    int n,m,k;
    cin>>n>>m>>k;

    for (int i=0; i<=n; i++) {
        graph.push_back(vector<pii>());
    }

    for (int i=0; i<m; i++) {
        int a,b,l;
        cin>>a>>b>>l;
        graph[a].push_back(pii(b,l));
        graph[b].push_back(pii(a,l));
    }

    for (int i=0; i<k; i++) {
        int u; cin>>u;
        is_storage[u] = 1;
    }

    int ans = -1;
    for (int i=1; i<=n; i++) {
        if (!is_storage[i]) continue;
        for (auto v: graph[i]) {
            if (is_storage[v.first]) continue;
            if (ans == -1) ans = v.second;
            ans = min(ans, v.second);
        }
    }
    cout<<ans<<endl;
}