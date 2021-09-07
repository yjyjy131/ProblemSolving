// 메모이제이션과 dfs 를 결합한 첫번째 방법은 시간초과

// j 번째 문자까지의 최소 dp 값을 계산한다. 

#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1001
char s[MAX];
int dp[MAX];
int INF = 1e9;

bool check(int i, int j) {
    if ( s[i] == 'B' && s[j] == 'O') {
        return true;
    } else if ( s[i] == 'O' && s[j] == 'J') {
        return true;
    } else if ( s[i] == 'J' && s[j] == 'B') {
        return true;
    } else return false;
    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 0;
    cin >> n ;

    for ( int i=1; i<n+1; i++) {
        cin >> s[i];
        dp[i] = INF;
    }

    dp[0] = 0, dp[1] = 0;

    for ( int j=1; j<n+1; j++ ) {
        for ( int i=j; i<n+1; i++ ) {
            if ( check(i, j) ) {
                int k = j - i ;
                dp[j] = min(dp[j], dp[i] + k*k);
            }
        }
    }

    if ( dp[n] == INF ) {
        cout << -1 ;
    } else {
        cout << dp[n] ;
    }

    return 0;
}