#include <iostream>
using namespace std;

#define INF 1000000000;

int fn_cnt = 0;
int cache[1000006];

// solve(x) will return min. number of coins required to form X.
int solve(int x) {
    fn_cnt++; // Tracking how many times this function was called.
    if (x < 0) {
        return INF;
    }

    if (cache[x] != -1) { // Cache is filled.
        return cache[x];
    }

    if (x == 1 || x == 5 || x == 7) {
        return 1;
    }

    // Let's try the 1 coin
    int cnt_taking_1_coin = 1 + solve(x-1);
    // Let's try the 5 coin
    int cnt_taking_5_coin = 1 + solve(x-5);
    // Let's try the 7 coin
    int cnt_taking_7_coin = 1 + solve(x-7);

    int ans = cnt_taking_1_coin;
    ans = min(ans, cnt_taking_5_coin);
    ans = min(ans, cnt_taking_7_coin);

    // Write to cache.
    cache[x] = ans;
    return ans;
}

int main() {
    for (int i=0; i<1000000; i++) {
        // -1 indicates, cache is not filled.
        cache[i] = -1;
    }

    // If we randomized, fn_cnt would not always be 4, but it will still run as fast.
    for (int i=800; i>=1; i--) {
        fn_cnt = 0;
        int ans = solve(i);
        cout<<i<<": ans = "<<ans<<" fn_cnt = "<<fn_cnt<<endl;
    }
}
