#include <iostream>
using namespace std;
 
#define INF 2000000000
 
int arr[200005];
int tree[4000006];
 
void initialize_tree(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
 
    int left_node = 2*node;
    int right_node = 2*node+1;
    int mid = (l+r)/2;
 
    initialize_tree(left_node, l, mid);
    initialize_tree(right_node, mid+1, r);
 
    tree[node] = min(tree[left_node], tree[right_node]);
}

void update_tree(int node, int l, int r, int pos, int val) {
    // Are we out of bounds.
    if (pos < l || pos > r) {
        return;
    }

    // Ok we're not out of bounds, so this
    // node MUST be updated.

    // We're at a leaf node. Trivial update.
    if (l == r) {
        tree[node] = val;
        return;
    }

    int left_node = 2*node;
    int right_node = 2*node+1;
    int mid = (l+r)/2;

    update_tree(left_node, l, mid, pos, val);
    update_tree(right_node, mid+1, r, pos, val);

    // Something might have changed, so let's update this.
    tree[node] = min(tree[left_node], tree[right_node]);
}
 
// This is the query.
int find_min(int node, int l,  int r, int ql, int qr) {
 
    if (qr < l /* query completely to the left */ ) {
        return INF;
    }
 
    if (ql > r /* query completely to the right */) {
        return INF;
    }
 
    // Clamp the query to the node.
    ql = max(ql, l);
    qr = min(qr, r);
 
    // query is covering the node, so everything
    // in this node is useful. No need to go to subschildren.
    if (ql <= l && qr >= r) {
        // The current node is useful to us.
        // So return it.
        return tree[node];
    }
 
    // query is completely inside node
    if (ql >= l && qr <= r) {
        int left_node = 2*node;
        int right_node = 2*node+1;
        int mid = (l+r)/2;
 
        int left_ans = find_min(left_node, l, mid, ql, qr);
        int right_ans = find_min(right_node, mid+1, r, ql, qr);
        return min(left_ans, right_ans);
    }
 
    return -1; // We shouldn't reach here.
 
}
 
int main() {
    int n, q;;
    cin>>n>>q;
 
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
 
    initialize_tree(
        1, /* seg_tree node 1 */ 
        0, /* node_1 start */
        n-1 /*node_1 end */
    );
 
    while (q--) {
        int qt, l, r;
        cin>>qt>>l>>r;

        if (qt == 1) {
            int pos = l;
            int val = r;
            pos--;

            update_tree(
                1, // seg tree node
                0, // 1st node left bound
                n-1, // 1st node right bound
                pos, // pos
                val
            );
        }
 
        if (qt == 2) {
            l--;
            r--;
            int ans = find_min(
             1,    /* seg_tree node 1 */
             0,    /* node 1 start */
             n-1,  /* node 1 end */
             l,    /* query start */
             r     /* query end */
            );
            cout<<ans<<endl;
        }
    }
}