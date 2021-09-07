#include <iostream>
#include <deque>
using namespace std;
#define MAX 101

char board[MAX][MAX];
int chk[MAX][MAX] = {0, };
int w=0, h=0;
int b_cnt=1, w_cnt=1;
deque <int> b_dq;
deque <int> w_dq;

void dfs(char c, int x, int y){

    int go_x[] = {1, 0, -1, 0};
    int go_y[] = {0, 1, 0, -1};

    for ( int i=0; i<4; i++) {
        int new_x = x + go_x[i];
        int new_y = y + go_y[i];

        if (new_x < 0 || new_x >= h || new_y < 0 || new_y >= w) continue;

        if ( chk[new_x][new_y] == 0 && board[new_x][new_y] == c) {
            chk[new_x][new_y] = 1;

            if ( c == 'W' ) {
                w_cnt += 1;
            } else if ( c == 'B' ) {
                b_cnt += 1;
            }

            dfs(c, new_x, new_y);

        } 
    }

}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> w >> h;

    for ( int i=0; i<h; i++ ) {
        for ( int j=0; j<w; j++ ){
            cin >> board[i][j] ; 
        }
    }

    for ( int i=0; i<h; i++ ) {
        for ( int j=0; j<w; j++ ){
            if ( chk[i][j] == 0 ) {
                chk[i][j] = 1;
                char curr_c = board[i][j];

                dfs(board[i][j], i, j);

                if ( curr_c == 'W' ) {
                    w_dq.push_back(w_cnt*w_cnt);
                } else if ( curr_c == 'B' ) {
                    b_dq.push_back(b_cnt*b_cnt);
                }

                w_cnt = 1;
                b_cnt = 1;

            } 
        }
    }


    int tmp = 0;
    while (!w_dq.empty()){
        tmp += w_dq.front();
        w_dq.pop_front();
    }
    
    cout << tmp << ' ';
    tmp = 0;
    while (!b_dq.empty()){
        tmp += b_dq.front();
        b_dq.pop_front();
    }

    cout << tmp ;
    
    return 0;
}