#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000007

typedef long long ll;

int n;
int grid[1002][1002];
ll cache[1002][1002];


// Counts the paths starting at x,y and reaching (n-1, n-1);
//
ll count_paths(int x, int y) {
    // Check for outerbounds.
    if (x >= n) return 0;
    if (y >= n) return 0; 

    if (grid[x][y] == 1) { // This is a trap.
        return 0;
    }

    if (x==n-1 && y==n-1) {
        // (()) -> 1, but the one path inside has 0 steps. is different from () -> 0
        return 1;
    }


    if (cache[x][y] != -1) {
        return cache[x][y];
    }

    ll ans = 0;
    // Let's move to the right.
    ans = ans + count_paths(x+1, y);
    ans = ans % MOD;

    // Let's move to the bottom.
    ans = ans + count_paths(x, y+1);
    ans = ans % MOD;

    cache[x][y] = ans;
    return ans;
}



int main() {
    cin>>n;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        for (int j=0; j<n; j++) {
            if (s[j] == '.') {
                grid[i][j] = 0; // Free space.
            }
            else {
                grid[i][j] = 1; // Trap.
            }
        }
    }

    // Actually for strings. 
    // But we're filling a long long array? How does it work.
    // Memset works for us only for 0, -1.
    // 0 -> 00000000000000..0 
    // -1 -> 11111111111..111
    memset(cache, -1, sizeof(cache));

    cout<< count_paths(0, 0) << endl;
}
