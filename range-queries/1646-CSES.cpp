#include <iostream>
using namespace std;

long long arr[200005];
long long pre[200005];

int main() {
    int n, q;
    cin>>n>>q;

    for (int i=1; i<=n; i++) {
        cin>>arr[i];
        pre[i] = pre[i-1] + arr[i];
    }

    while (q--) {
        int l, r;
        cin>>l>>r;
        // O(1)
        long long ans = pre[r] - pre[l-1];
        cout<<ans<<endl;
    }

}