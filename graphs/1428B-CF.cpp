#include <iostream>
using namespace std;

void solve() {
    int n; cin>>n;
    string s;
    cin>>s;

    int all_right = 1;
    int all_left = 1;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '<') all_right = 0;
        if (s[i] == '>') all_left = 0;
        if (s[i] == '-') {
            ans = ans + 2;
            if (i > 0  && s[i-1] == '-') ans--;
        }
    }
    if (s[0] == '-' && s[n-1] == '-') ans--;

    if (all_right || all_left) {
        cout<<n<<endl;
        return;
    }
    cout<<ans<<endl;
}

int main() {
    int n;
    cin>>n;
    while (n--) {
        solve();
    }
}