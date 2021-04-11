#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n; 
    cin>>n;


    for (int i=0; i < 5; i++) {
        // Is the ith bit set or not?
        int bottom = (1 << i);
        int check = (n & bottom);

        if (check == 0) {
            cout<<i<<" th bit is not set"<<endl;
        }
        else {
            cout<<i<<" th bit is set"<<endl;
        }
    }

    for (int i=31; i >= 0; i--) {
        if (n & (1<<i)) cout<<1;
        else cout<<0;
    }
    cout<<endl;

}