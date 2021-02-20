#include <iostream>
#include <map>
using namespace std;
 
map<string, int> m;
 
int main() {
    int n;
    cin>>n;
 
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
 
        if (m.find(s) == m.end()) {
            // NAME does not exist yet.
            cout << "OK" << endl;
            m[s] = 1; // We have 1 string with this value.
        }
        else {
            // get the value of m[s];
            int suffix = m[s];
            cout<<s<<suffix<<endl;
            m[s] = m[s] + 1;
        }
    }
}
