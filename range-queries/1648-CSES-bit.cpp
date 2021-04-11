#include <iostream>
using namespace std;

typedef long long ll;

ll bit[200005];

void update(int x, ll val) {
    while (x < 200005) {
        bit[x] += val;
        x += (x & -x);
    }
}

ll get_sum(int x) {
    ll ans = 0;
    while (x) {
        ans = ans + bit[x];
        x -= (x & -x);
    }
}

int main() {

}