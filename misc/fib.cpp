#include <iostream>
using namespace std;

int fib(int x) {
    if (x == 0) return 1;
    if (x == 1) return 1;
    return fib(x-1) + fib(x-2);
}

int cache[2000];
int fib2(int x) {
    if (x == 0) return 1;
    if (x == 1) return 1;

    if (cache[x] != 0) {
        return cache[x];
    }

    cache[x] = fib2(x-1) + fib2(x-2);
    return cache[x];
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n)<<endl;

    // ALL DP Problems, you can write as memoization problems.
    // When written memoization, it's called top-down DP.
    // When solving smaller cases first, iterativelty, it's called bottom up DP.

    // Version 1.
    // O(100 * 2^100)
    for (int i=0; i<100; i++) {
        cout<<fib(i)<<endl;
    }

    // Version 2.
    // O(100)
    for (int i=0; i<100; i++) {
        cout<<fib2(i)<<endl;
    }

    // Version 3.
    // Almost same as Version 2, slightly bit faster.
    int cache3[1000];
    cache3[0] = 1;
    cache3[1] = 1;
    for (int i=2; i<100; i++) {
        cache3[i] = cache3[i-1] + cache3[i-2];
    }
}
