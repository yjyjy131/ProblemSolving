#include <iostream>
#include <cstring>
#include <queue>
#define MAX 201

using namespace std;

int n;
int r1, c1, r2, c2;

int arr[MAX][MAX];
const int go_x[6] = {-2, -2, 0, 0, 2, 2};
const int go_y[6] = {-1, 1, -2, 2, -1, 1};


int main(void) {

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(arr, -1, sizeof(arr));
    
    queue<pair<int, int>> dq;
    dq.push({r1, c1});
    arr[r1][c1] = 0;

    while(!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;

        dq.pop();

        for (int i=0; i<6; i++){
            int nx = x + go_x[i];
            int ny = y + go_y[i];

            if (!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;

            if (arr[nx][ny] == -1) {
                arr[nx][ny] = arr[x][y] + 1;
                dq.push({nx, ny});
            }
        }

    }

	if (arr[r2][c2] == -1)
		cout << -1 << "\n";
	else
		cout << arr[r2][c2] << "\n";
	return 0;

}