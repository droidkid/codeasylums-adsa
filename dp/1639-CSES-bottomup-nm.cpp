#include <iostream>
using namespace std;
 
int dp[5003][5003];
 
int main() {
    string s1;
    string s2;
    cin>>s1>>s2;
 
    int n = s1.size();
    int m = s2.size();
 
    for (int i=0; i<5003; i++) {
        for (int j=0; j<5003; j++) {
            dp[i][j] = 1000000;
        }
    }
 
 
    for (int i=n; i>=0; i--) {
        for (int j=m; j>=0; j--) {
 
            if (i==n && j==m) {
                dp[i][j] = 0;
                continue;
            }
 
            if (i==n) {
                dp[i][j] = 1 + dp[i][j+1];
                continue;
            }
 
            if (j==m) {
                dp[i][j] = 1 + dp[i+1][j];
                continue;
            }
 
            if (s1[i] == s2[j]) {
                dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
            }
            // This represents
            // adding a character to second string
            // or removing a character from first string.
            dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
 
            // This represents
            // adding a character to first string
            // or removing a character from second string.
            dp[i][j] = min(dp[i][j], 1 + dp[i][j+1]);
 
            // This is basically replacing one of the characters to
            // match the others.
            dp[i][j] = min(dp[i][j], 1 + dp[i+1][j+1]);
        }
    }
    cout<<dp[0][0]<<endl;
}