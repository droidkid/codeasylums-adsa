#include <iostream> 
using namespace std; 

void solve() { 
    int n; 
    cin>>n; 
    string b; 
    cin>>b; 
    string a = ""; 
    int prev_d = -1; 
    for (int i=0; i<n; i++) { 
       int val = b[i] - '0'; // converting char to int. 
       if (val + 1 != prev_d) { 
            a = a + "1"; 
            prev_d = val + 1; 
       } else { 
            a = a + "0"; 
            prev_d = val + 0; 
       } 
    } 
    cout<<a<<endl; 
} 

int main() { 
        int t; 
        cin>>t; 
        while (t--) { 
                solve(); 
            } 
} 
