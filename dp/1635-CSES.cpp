#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007
typedef long long ll;

vector<int> coin_denominations;
ll cache[1000006];

// RETURNS, no. of ways to get n using coin_denominations.
ll solve(ll n) {
    ll ans = 0;

    // () -> empty set
    // (0) -> set with 0 elements
    // null set -> there is no set.
    //
    //
    // solution for 9:
    // ( (2,2,5), (2,5,2) .... (3,2,2,2) ) = 8
    // 
    // solution for 0:
    // ( () ) -> 1
    //
    // solution for negative numbers: the answer for this is 0
    // ( ) -> 0

    if (n == 0) return 1;
    if (n <  0)  return 0;

    if (cache[n] != -1) {
        return cache[n];
    }

    for (int i=0; i<coin_denominations.size(); i++) {
        // Take coin_denominations[i] as first coin.
        // Exapmle: if you have 9, take 3 -> find the answer for 6.

        ans = ans + solve(n-coin_denominations[i]);
        ans = ans % MOD;

        /* ALTERNATIVE WAY OF WRITING BELOW, NO NEED TO CHECK FOR BASE CASES IN THIS WAY.
        if (n - coin_denominations[i] > 0) {
            ans = ans + solve(n-coin_denominations[i]);
            ans = ans % MOD;
        }
        
        // If one coin makes it zero, just add 1. We've found a combination.
        // If you have 5, you took 5, now you're left with 0.
        if (n - coin_denominations[i] == 0) {
            ans = ans + 1;
            ans = ans % MOD;
        }
        */
    }

    cache[n] = ans;
    return ans;
}

int main() {
    for (int i=0; i<1000006; i++) {
        cache[i] = -1;
    }

    int n, x;
    cin>>n>>x;
    for (int i=0; i<n; i++) {
        int c; cin>>c;
        coin_denominations.push_back(c);
    }
    cout<<solve(x)<<endl;
}
