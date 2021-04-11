#include <iostream>
#include <algorithm>
using namespace std;

long long arr[200005];
long long chunked_arr[20005];

#define INF 2000000000ll

int main() {
    int n, q;
    cin>>n>>q;

    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int chunk_size = 350;
    int chunk_idx = -1;

    chunked_arr[0] = INF;

    for (int i=0; i<n; i++) {
        if (i % chunk_size == 0) {
            chunk_idx++;
            chunked_arr[chunk_idx] = INF;
        }

        chunked_arr[chunk_idx] = 
            min(arr[i], chunked_arr[chunk_idx]);
    }

    while (q--) {
        int l, r;
        cin>>l>>r;
        l--;
        r--;

        long long ans = INF;
        int idx = l;

        while (idx % chunk_size != 0 && idx <= r) {
            ans = min(ans, arr[idx]);
            idx++;
        }

        while (idx + chunk_size -1 <= r) {
            ans = min(ans, chunked_arr[idx / chunk_size]);
            // We get to skip these many elements
            // Because we've stored this in the 
            // chunk array.
            idx = idx + chunk_size;
        }

        while (idx <= r) {
            ans = min(ans, arr[idx]);
            idx++;
        }
        cout<<ans<<endl;
    }
}