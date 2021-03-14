#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<string> maze;

int dist[1003][1003];
int dir[1003][1003];

void pr(int n, int m) {

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (dist[i][j] == -1) {
                cout<<". ";
            }
            else {
                if (dir[i][j] == 0) {
                    cout<<"R ";
                }
                if (dir[i][j] == 1) {
                    cout<<"L ";
                }
                if (dir[i][j] == 2) {
                    cout<<"D ";
                }
                if (dir[i][j] == 3) {
                    cout<<"U ";
                }
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    int n, m;
    cin>>n>>m;

    for (int i=0; i<n; i++) {
        string s; cin>>s;
        maze.push_back(s);
    }


    int sx;
    int sy; 
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            dist[i][j] = -1;
        }
    }

    queue<pii> q;
    q.push(pii(sx, sy));
    dist[sx][sy] = 0;
    // pr(n, m);

    while (!q.empty()) {
        pii u = q.front();
        int x = u.first;
        int y = u.second;
        q.pop();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i=0; i<4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i];

            // Checks we need to do.
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (maze[nx][ny] == '#') continue; // Wall, so continue;
            if (dist[nx][ny] != -1) continue; // This has already been visited.
            dist[nx][ny] = 1 + dist[x][y];
            dir[nx][ny] = i;
            q.push(pii(nx, ny));
        }
        // pr(n,m);
    }

    int minDist = 0;
    int dx;
    int dy;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == 'B') {
                minDist = dist[i][j];
                dx = i;
                dy = j;
            }
        }
    }

    if (minDist == -1) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<minDist<<endl;

    string steps;
    int cx = dx;
    int cy = dy;

    int cnt = 0;
    // Retracing Path.
    while (!(cx == sx && cy == sy)) {
        int d = dir[cx][cy];
        // Let's retrace our steps.
        if (d == 0) {
            steps.push_back('R');
            cy = cy - 1;
        }
        if (d == 1) {
            steps.push_back('L');
            cy = cy + 1;
        }
        if (d==2) {
            steps.push_back('D');
            cx = cx - 1;
        }
        if (d==3) {
            steps.push_back('U');
            cx = cx + 1;
        }
    }
    reverse(steps.begin(), steps.end());
    cout<<steps<<endl;
}