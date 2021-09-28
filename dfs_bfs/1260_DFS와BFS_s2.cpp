#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int n, m, v;
int map[MAX][MAX];
bool visited[MAX];
queue <int> bfs_chk;

void bfs(int x) {
    cout << x+1 << ' ';
    bfs_chk.push(x);
    visited[x] = 1;

    while ( !bfs_chk.empty() ) {
        x = bfs_chk.front();
        bfs_chk.pop();
        for (int i=0; i<n; i++){
            if ( map[x][i] == 1 && visited[i] == 0 ) {
                bfs_chk.push(i);
                cout << i+1 << ' ';
                visited[i] = 1;
            }
        }
    }
}

void dfs(int x) {
    cout << x+1 << ' ';
    visited[x] = 1;

    for ( int i=0; i<n; i++ ) {
        if ( map[x][i] == 1 && visited[i] == 0 ) {
            dfs(i);
        }
    }

}

int main(void) {

    cin >> n >> m >> v ;

    for ( int i=0; i<m; i++ ) {
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 1;
        map[b-1][a-1] = 1;
    }

    for ( int i=0; i<n; i++) {
        map[i][i] = 0;
    }

    visited[v-1] = 1;
    dfs(v-1);

    for ( int i=0; i<MAX; i++) {
        visited[i] = 0;
    }

    cout << '\n';

    visited[v-1] = 1;
    bfs(v-1);
    return 0;
}