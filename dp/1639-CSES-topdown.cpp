#include <iostream>
#include <cstring>
using namespace std;

/*
int solve(string s1, string s2) {
    if (s1 == s2) return 0; // Edit distance is 0. No need to change any characters.

    if (s1 == "") {
        // s1 is empty.
        return s2.size();
    }

    if (s2 == "") {
        return s1.size();
    }


    // Let's add s2[0] to s1
    string n1 = s2[0] + s1;
    string n2 = s2;
    // Now s1[0] and s2[0] are equal. Find the answer for s1[1...n], s2[1..n];
    ll ans = 1 + solve(n1.substr(1), n2.substr(1));


    // Let's add s1[0] to s2
    n1 = s1;
    n2 = s1[0] + s2;
    // Now s1[0] and s2[0] are equal.
    ans = min(ans, 1 + solve(n1.substr(1), n2.substr(1)));



    // Let's try removing the first character from s1
    n1 = s1.substr(1);
    n2 = s2;
    ans = min(ans, 1 + solve(n1, n2));

    // Let's try removing the first character from s2
    n1 = s1;
    n2 = s2.substr(1);
    ans = min(ans, 1 + solve(n1, n2));

    if (s1[0] == s2[0]) {
        n1 = s1.substr(1);
        n2 = s2.substr(1);
        ans = min(ans, solve(n1, n2));
    }

    n1 = s2[0] + s1.substr(1);
    n2 = s2; 
    ans = min(ans, 1+solve(n1.substr(1), s2.substr(1));
}
*/


string s1;
string s2;

int cache[5000][5000];

// Solve for s1[i....] and s2[j...]
int solve(int i, int j) {
    int ans = 50004; // INFINITY.

    if (cache[i][j] != -1) {
        return cache[i][j];
    }

    if (i==s1.size() && j==s2.size()) {
        return 0;
    }

    if (i==s1.size()) {
        return 1 + solve(i, j+1);
    }

    if (j==s2.size()) {
        return 1 + solve(i+1, j);
    }

    if (s1[i] == s2[j]) {
        ans = min(ans, solve(i+1, j+1));
    }

    // Let's add character from s1 to s2
    ans = min(ans, 1 + solve(i, j+1));
    // Let's add character from s2 to s1
    ans = min(ans, 1 + solve(i+1, j));

    // Let's remove a character from s1
    ans = min(ans, 1 + solve(i+1, j));
    // Let's remove a character from s2
    ans = min(ans, 1 + solve(i, j+1));

    // Let's replace a character from s1 to s2.
    ans = min(ans, 1 + solve(i+1, j+1));

    // cout<<"solving for ("<<s1.substr(i)<<" "<<s2.substr(j)<<" ): "<<ans<<endl;
    cache[i][j] = ans;
    return ans;
}

int main() {
    cin>>s1;
    cin>>s2;
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, 0)<<endl;
}
