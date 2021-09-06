/* 
점화식이  dp[i] = max({dp[i-3]*2, dp[i-4]*3, dp[i-5]*4}); 인 이유
n 이 1 ~ 6 인 경우는 자기자신의 수와 A의 최대수가 같으므로, 7의 경우부터 따져야한다. 
A 사용 개수가 4개를 초과하면 그때부터는 복사 붙여넣기만을 하는 것이 더 많은 A 를 만들 수 있다. 
따라서 복사 붙여넣기를 할 수 있는 경우는 크게 A를 사용하는 3가지 경우의 수로 나눌 수 있다. 
case1. A ctrl+A, ctrl+C, ctrl+V, ctrl+V, ctrl+V, ctrl+V : dp[i-5]*4 ( A 1번 , 복붙 2번)
case2. A A ctrl+A, ctrl+C, ctrl+V, ctrl+V, ctrl+V: dp[i-4]*3 ( A 2번 , 복붙 3번)
case3. A A A ctrl+A, ctrl+C, ctrl+V, ctrl+V : dp[i-3]*2 ( A 3번 , 복붙 4번)
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int main(void) {
    int n ;
    cin >> n;
    
    long dp[MAX] = {0, };

    for ( int i=0; i<7; i++) {
        dp[i] = i;
    } 

    for (int i=7; i<=n; i++) {
        dp[i] = max({dp[i-3]*2, dp[i-4]*3, dp[i-5]*4});
    }

    cout << dp[n] ;

    return 0;
}
