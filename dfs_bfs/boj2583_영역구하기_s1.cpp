#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 101

int m, n, k;
int cnt = 0;
bool visited[MAX][MAX];
int board[MAX][MAX];

int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y) {
    // 주어진 board 범위를 넘어가면 함수 종료
    cnt ++;
    visited[x][y] = true;


    int nx, ny;
    for (int i=0; i<4; i++){
        nx = x + go[i][0]; 
        ny = y + go[i][1];
        
        if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if (board[nx][ny]==0 && !visited[nx][ny]) dfs(nx, ny);

    }

}


void make_box(int x1, int y1, int x2, int y2){
    for (int i=x1; i<x2; i++){
        for (int j=y1; j<y2; j++){
            board[i][j] = 1;
            visited[i][j] = true;
        }
    }
}


int main(void) {
    cin >> m >> n >> k;

    int x1, y1, x2, y2;
    for (int i=0; i<k; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        make_box(x1, y1, x2, y2);
    }

    vector <int> ans;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (board[i][j] == 0 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    }

}
