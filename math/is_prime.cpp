#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    // Print YES if n is prime.
    // Else NO.

    // Don't divide by 1 or n.
    // Check upto sqrt of n
    // Because if a number greater than sqrt of n
    // was dividing n, then there would have been 
    // another number < sqrt of n which divdes it.
    for (int i=2; i*i <= n; i++) {
        if (n % i == 0) {
            cout<<"NOT A PRIME!"<<endl;
            return 0;
        }
    }

    cout<<"IS A PRIME"<<endl;
}