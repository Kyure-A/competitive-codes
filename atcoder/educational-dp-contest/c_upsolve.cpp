/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int n; cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(3)); // dp[i][j] .. [i] = num, [j] = a(0) or b(1) or c(2);

  for (int i = 1; i <= n; ++i)
    {
      int a, b, c; cin >> a >> b >> c;
      
      if (i == 1)
	{
	  dp[i][0] = a;
	  dp[i][1] = b;
	  dp[i][2] = c;
	}
      else
	{
	  dp[i][0] = max(dp[i - 1][1] + a, dp[i - 1][2] + a);
	  dp[i][1] = max(dp[i - 1][0] + b, dp[i - 1][2] + b);
	  dp[i][2] = max(dp[i - 1][0] + c, dp[i - 1][1] + c);
	}
    }

  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;

  return 0;
}
