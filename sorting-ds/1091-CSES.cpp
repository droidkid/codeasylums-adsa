#include <iostream>
#include <set>
using namespace std;

multiset<int> tickets;

int main() {
    int n, m;
    cin>>n>>m;

    for  (int i=0; i<n; i++) {
        int x; cin>>x;
        tickets.insert(x);
    }

    for (int i=0; i<m; i++) {
        int cur; cin>>cur;

        auto it = tickets.upper_bound(cur);
        if (it == tickets.begin()) {
            cout << -1 << endl;
            continue;
        }
        it--;
        cout<< (*it) << endl;
        tickets.erase(it);
    }

}
