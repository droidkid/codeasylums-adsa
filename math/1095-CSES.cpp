#include <iostream>
using namespace std;

typedef long long ll;

#define MOD 1000000007

// Find a^b modulo MOD
ll pow_mod(ll a, ll b) {
    if (b == 0) {
        return 1;
    }

    // O(lg n)
    ll half = pow_mod(a, b/2);
    ll ans = (half * half) % MOD;

    if ( b % 2 == 1) {
        ans = ans * a % MOD;
    }

    return ans;
}

ll pow_naive(ll a, ll b) {
    ll ans = 1;
    // O(n)
    for (ll i=0; i<b; i++) {
        ans = ans * a % MOD;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        ll a, b;
        cin>>a>>b;
        cout<<pow_mod(a, b)<<endl;
    }
}