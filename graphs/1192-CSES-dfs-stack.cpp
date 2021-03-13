#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;

vector<string> maze;

void bfsAndMarkConnected(int x, int y) {

    stack<pii> s;
    s.push(pii(x, y));

    while (!s.empty()) {
        pii curr = s.top();
        s.pop();

        int x = curr.first;
        int y = curr.second;

        maze[x][y] = '*'; // This is visited now.

        // Try to push unvisited neighbours onto queue.
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i=0; i<4; i++) {
         int nx = x + dx[i];
         int ny = y + dy[i];

         if (nx < 0 || nx >= maze.size()) continue;
         if (ny < 0 || ny >= maze[0].size()) continue;
         if (maze[nx][ny] == '#') continue; // It's a wall.
         if (maze[nx][ny] == '*') continue; // It's been visited before.
         s.push(pii(nx, ny));
        }
    }

}

int main() {
    int n, m;
    cin>>n>>m;

    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        maze.push_back(s);
    }
    
    // Nodes. Edges.
    
    int rooms = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == '#') {
                // This is a wall. Ignore.
                continue;
            }

            if (maze[i][j] == '*') {
                // This floor was already visited.
                // So don't count this as a extra room.
                continue;
            }

            if (maze[i][j] == '.') {
                // This is a path. Now I need to find
                // which cells are connected to this.
                // I don't want to visit cells which
                // are already connected.

                bfsAndMarkConnected(i, j);
                rooms++;
            }
        }
    }
    cout<<rooms<<endl;


}