#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;

    while (n) {
        int last_one = (n & -n);
        cout<< last_one << endl;
        n = n - last_one;
    }
}