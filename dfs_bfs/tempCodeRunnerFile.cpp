#include <iostream>
#include <vector>
#include <queue>
#define MAX 200

using namespace std;

int n;
int r1, c1, r2, c2;

int arr[MAX][MAX];
int go[6][2] = {{-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main(void) {

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    fill(arr[0], arr[n], 0);
    arr[c1][r1] = 1;
    
    queue <pair<int, int>> dq;
    dq.push({c1, r1});

    while(!dq.empty()){
        int y = dq.front().first;
        int x = dq.front().second;

        dq.pop();

        for (int i=0; i<6; i++){
            int nx = x + go[i][1];
            int ny = y + go[i][0];

            if (nx<0 || nx>=n || ny<0 || ny>=n) continue;

            if (arr[nx][ny] == 0) {
                arr[nx][ny] = arr[x][y] + 1;
                dq.push({nx, ny});
            }
        }

    }

	if (arr[c2][r2] == 0)
		cout << -1 << "\n";
	else
		cout << arr[c2][r2] << "\n";
	return 0;

}