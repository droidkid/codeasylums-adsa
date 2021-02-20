#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// Print out number of ways to get n, using a dice
void print_dice(int n, vector<int> v) {
    if (n == 0) {
        for (int i=0; i<v.size(); i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    int ans = 0;
    // For each side of the dice.
    for (int i=1; i<=6; i++) {
        if (n - i >= 0) {
            vector<int> nv;
            for (int i=0; i<v.size(); i++) {
                nv.push_back(v[i]);
            }
            nv.push_back(i);
            print_dice(n-i, nv);
        }
    }
}

int count_dice(int n) {
    if (n == 0) {
        return 1;
    }

    int ans = 0;
    // For each side of the dice.
    for (int i=1; i<=6; i++) {
        if (n - i >= 0) {
            ans += count_dice(n-i);
        }
    }
    // cout<<"CALCULATING FOR "<<n<<" "<<ans<<endl;
    return ans;
}

// DP Version.
long long cache[1000006]; // random limit; Filled with -1;
long long  count_dice_dp(int n) {
    if (cache[n] != -1) {
        // cout<<"RETURNING FROM CACHE FOR "<<n<<" "<<cache[n]<<endl;
        return cache[n];
    }
    if (n == 0) {
        return 1;
    }

    long long ans = 0;
    // For each side of the dice.
    for (int i=1; i<=6; i++) {
        if (n - i >= 0) {
            ans += count_dice_dp(n-i);
            ans %= 1000000007;
        }
    }
    // cout<<"FILLING CACHE FOR "<<n<<" "<<ans<<endl;
    cache[n] = ans;
    return ans;
}


int main() {
    int n;
    memset(cache, -1, sizeof(cache));
    cin>>n;
    cout<<count_dice_dp(n)<<endl;
}
