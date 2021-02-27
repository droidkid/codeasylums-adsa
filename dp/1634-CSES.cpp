#include <iostream>
#include <vector>
using namespace std;



int cache[1000006];
vector<int> coin_denominations;

// Solve(n) will return, the min. number of coins to get 'n'.
int solve(int n) {
    if (n == 0) {
        return 0;
    }

    if (cache[n] != -2) {
        return cache[n];
    }
    
    int ans = -1;

    for (int i=0; i<coin_denominations.size(); i++) {
        int coin = coin_denominations[i];
        if (n >= coin) {
            // I can take coin!. But is it the best answer?
            int check = solve(n-coin);
            // That means we didn't get a negative number, so it is possible.
            if (check >= 0) {
                // This is a potential answer.
                if (ans == -1) ans = 1 + check;
                if ((1 + check) < ans) ans = (1 + check);
            }
        }
    }
    // cout<<n<<" "<<ans<<endl;
    cache[n] = ans;
    return ans;
}

int main() {
        for (int i=0; i<=1000000; i++) {
            cache[i] = -2; // -2 means, never filled.
        }
        int n, x;
        cin>>n>>x;
        // INPUT.
        for (int i=0; i<n; i++) {
            int coin; cin>>coin;
            coin_denominations.push_back(coin);
        }

        cout<<solve(x)<<endl;
}
