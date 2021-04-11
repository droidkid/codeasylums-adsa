#include <iostream>
using namespace std;
 
long long arr[200005];
 
int main() {
    int n, q;
    cin>>n>>q;
 
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
 
    while (q--) {
        int l, r;
        cin>>l>>r;
        l--; r--;
        long long ans = 0;
        for (int i=l; i<=r; i++) {
            ans = ans + arr[i];
        }
        cout<<ans<<endl;
    }
}