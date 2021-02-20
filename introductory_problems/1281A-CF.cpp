#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        if (s.size() >= 2 && s.substr(s.size()-2, s.size()) == "po") {
            cout<<"FILIPINO"<<endl;
            continue;
        }
        if (s.size() >= 4 && 
            s.substr(s.size()-4, s.size()) == "desu" || 
            s.substr(s.size()-4, s.size()) == "masu" 
        ) {
            cout<<"JAPANESE"<<endl;
            continue;
        }
        cout<<"KOREAN"<<endl;
    }
}
