#include <iostream>
using namespace std;

// 0 means it is a prime;
// Initially everything is assumed prime.
int sieve[1000005];

void fill_sieve(int n) {
    for (int i=2; i*i < n; i++) {
        if (sieve[i] != 0) continue; 
        // Now we know 'i' is a prime;
        // Mark all multiples of i as prime.

        for (int j = i*i; j<n; j=j+i) {
            // j is a composite number.
            sieve[j] = 1;
        }
    }
}


int main() {
    fill_sieve(1000);

    for (int i=2; i<1000; i++) {
        if (sieve[i] == 0) cout<<i<<endl;
    }

}