#include <iostream>
#include <vector>
using namespace std;

vector<string> maze;

void findAndMarkAllConnectedFloors(int x, int y) {
    if (x < 0 || x >= maze.size()) return;
    if (y < 0 || y >= maze[0].size()) return;
    if (maze[x][y] == '#') return;

    // VERY IMPORTANT: DON'T REVISIT NODES AGAIN!!!!!
    if (maze[x][y] == '*') return;

    // Mark as visited.
    maze[x][y] = '*';

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        findAndMarkAllConnectedFloors(nx, ny);
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

                findAndMarkAllConnectedFloors(i, j);
                rooms++;
            }
        }
    }
    cout<<rooms<<endl;


}