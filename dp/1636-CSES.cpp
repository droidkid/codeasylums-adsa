#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii; // Pair.

vector<int> coins;
int cache[1000006][2];

// int cache[1000006][1000006]; 
// 10^12. 10^9 1GB, 10^12 -> 100GB, absurd, you can't allocate this much.

// I'm picking coins from currIdx. 
int solve(int n, int currIdx) {

    if (n == 0) return 1;
    if (n <= 0) return 0;      // Invalid
    if (currIdx < 0) return 0; // Invalid

    // Return from cache if it exists.
    if (cache[n][currIdx] != -1) {
        return cache[n][currIdx];
    }
    ll ans = 0;
    // Pick as much as you want, but always decrement the index.
    int sum = n;
    while (sum >= 0) {
        ans = ans + solve(sum, currIdx-1);
        ans = ans % MOD;
        sum = sum - coins[currIdx];
    }
//  cout<<n<<" "<<currIdx<<": "<<ans<<endl;
    cache[n][currIdx] = ans;
    return ans;
}

int solve2(int n, int currIdx) {

    cache[0][0] = 1;
    int flip = 1;

    while (currIdx >= 0) {
        for (int i=0; i<=n; i++) {
            cache[i][flip] = 0;
            if (i - coins[currIdx] >= 0) {
                cache[i][flip] += cache[i-coins[currIdx]][flip];
            }
            cache[i][flip] += cache[i][1-flip];
            cache[i][flip] %= MOD;
        }
        currIdx--;
        flip = 1-flip;
    }

    return cache[n][1-flip];
}


int main() {
    int n, x;
    scanf("%d%d",&n, &x);
    for (int i=0; i<n; i++) {
        int c;
        scanf("%d",&c);
        coins.push_back(c);
    }
    cout<<solve2(x, n-1)<<endl;;
}
