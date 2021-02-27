#include <iostream>
using namespace std;

// 1. Usually to avoid overflow issues for Online judges, they ask you to do this.
#define MOD 1000000007

typedef long long ll;

// Returns n^x % MOD
ll my_pow(ll n, ll x) {
    ll ans = 1;
    for (int i=0; i<x; i++) {
        ans = ans * n;
        ans = ans % MOD;
    }
    return ans;
}

ll my_pow2(ll n, ll x) {
    if (x == 0) {
        return 1;
    }
    ll temp = my_pow2(n, x/2);
    ll ans = temp * temp % MOD;
    if (x % 2 == 1) {
        temp = temp * n % MOD;
    }
    return ans;
}



int main() {
    int n;
    cin>>n;

    // Find probability that after N dice throws
    // you get a palindrome.
   
    int num_pow = n/2;
    if (n%2 == 1) { 
        num_pow++;
    }// ODD

    ll numerator = my_pow(6, num_pow);  // 6 ^ (n/2);
    // 2 issues. 
    // 1. It returns in double format.
    // 2. It does not calculate the power in modulo.

    ll denominator = my_pow(6, n); // 6 ^ (n)

    /*
     * THIS IS WRONG!!!!!!!. DON't DO THIS.
     * ll ans = numerator / denominator;
     * ans = ans % MOD;
    */

    // Remember, we can't do numerator / denominator? We don't want double in modulo arithmetic.
    // What you can do is numberator * (denominator_inverse)
    // denominator_inverse = my_pow(6, MOD-2)

    ll denominator_inverse = my_pow(denominator, MOD-2);
    ll ans = (numerator * denominator_inverse) % MOD;

    cout<< ans << endl;
}
