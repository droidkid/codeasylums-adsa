#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    // If there are n elements.
    // Your mask needs to be from 0 to (1<<n) - 1;

    for (int mask = 0; mask < (1<<n); mask++) {

        // 1 mask corresponds to one subset.

        // Let's check if the ith element is part
        // of this subset.
        for (int i=0; i<n; i++) {
            if (mask & (1<<i)) {
                // The ith bit is set in the mask.
                // So the ith element is part of this subset.
                cout<<(i+1)<<" ";
            }
        }
        cout<<endl;
    } 
}