#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int x; cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
}
