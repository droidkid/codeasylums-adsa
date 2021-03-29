#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
int longest; // This will store our final answer.

int find_longest(int u, int p) {
    vector<int> child_max_path_lengths;
    for (auto v: tree[u]) {
        if (v == p) continue;
        // For child 'v', 
        // get the longest path starting from 'v'.
        child_max_path_lengths.push_back(
            find_longest(v, u)
        );
    }

    // If there are lesser than 2 children, we want to cancel out the 1 we're adding below.
    sort(child_max_path_lengths.begin(), child_max_path_lengths.end());
    reverse(child_max_path_lengths.begin(), child_max_path_lengths.end());

    if (child_max_path_lengths.size() == 0) {
        // Do nothing, no path here.
    }

    if (child_max_path_lengths.size() == 1) {
        // Do something
        int temp = child_max_path_lengths[0] + 1;
        longest = max(longest, temp);
    }

    if (child_max_path_lengths.size() >= 2) {
        // Do something
        int temp = child_max_path_lengths[0] + 2 + child_max_path_lengths[1];
        longest = max(longest, temp);
    }

    return 1 + child_max_path_lengths[0];
}


int main() {

    int n;
    cin>>n;

    for (int i=0; i<=n; i++) {
        tree.push_back(vector<int>());
    }

    // There will be n-1 edges.
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;

        // We really don't know the root.
        // So let's store it both ways.
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    find_longest(n /* this is arbitarily chosen*/ , 0 /* dummy parent */);

    cout<<longest<<endl;
}