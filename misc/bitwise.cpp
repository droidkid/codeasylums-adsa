#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, b; 
    cin>>n>>b;

    vector<int> bits;

    while (n!=0) {
        int rem = n % b;
        bits.push_back(rem);
        n = n/b;
    }

    reverse(bits.begin(), bits.end());

    for (auto bit: bits) {
        cout<<bit<<" ";
    }
    cout<<endl;


}