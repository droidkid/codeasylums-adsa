#include <iostream>
using namespace std;
 
void solve() {
    int n;
    cin>>n;
 
    int cnt[26];
    for (int i=0; i<26; i++) {
        cnt[i] = 0;
    }
 
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        for (int j=0; j<s.size(); j++) {
            cnt[s[j]-'a']++;
        }
    }
 
    for (int i=0; i<26; i++) {
        if (cnt[i] % n != 0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
 
int main() {
    int t;
    cin>>t;
    
    int cnt[26];
 
    while (t--) {
        solve();
    }
}
