#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> v;

ll num_products(ll t, ll lim) {
    ll ans = 0;
    for (int i=0; i<v.size(); i++) {
        ans = ans + (t / v[i]);
        if (ans >= lim) return ans;
    }
    return ans;
}

int main() {
    ll n, t;
    cin>>n>>t;

    for (int i=0; i<n; i++) {
        int x; cin>>x;
        v.push_back(x);
    }

    ll lo = 1;
    ll hi = v[0] * t;

    while (lo < hi) {
        ll mid = lo + (hi-lo) / 2;
        ll tot = num_products(mid, t);
        if (tot >= t) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    cout<<lo<<endl;
}
