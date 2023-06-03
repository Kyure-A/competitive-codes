/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/modint>
// #include <boost/multiprecision/cpp_int.hpp>
/* ------------------------------  using  ------------------------------ */
using namespace std;
// using namespace atcoder;
// using namespace boost::multiprecision;
/* ------------------------------  define ------------------------------ */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<int> x(n + 1); rep(i, n) cin >> x[i + 1];
  
  vector<int> bonus(n + 1, 0); // -1 で初期化しようとしていたが，bonus がない状態は bonus が 0 であることなので 0 でいい

  for (int i = 0; i < n; ++i)
    {
      int c, y; cin >> c >> y;
      bonus[c] = y;
    }
  
  // dp[i 回のコイントスが行われている (0 <= i <= n)][j 回目のカウントが行われている(0 <= j <= n)]
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
  
  dp[0][0] = 0;
  rep(i, n + 1) if (i > 0) dp[0][i] = -99999999999; // i < j なのはおかしいので -\infty する
  
  for (int i = 1; i <= n; ++i)
    {
      // 表が出た場合
      for (int j = 1; j <= i; ++j)
	{
	  dp[i][j] = dp[i - 1][j - 1] + x[i] + bonus[j]; // 普段の dp (?) とは違って dp_i と dp_j が連動している
	}
      
      // 裏が出た場合 (i < j であるときを省く)
      dp[i][0] = 0;
      for (int j = 0; j < i; ++j)
	{
	  dp[i][0] = max(dp[i][0], dp[i - 1][j]); // // i - 1 回目のコイントスかつ，j 回目のカウントで失敗した場合
	}
    }

  long long answer = 0;
  for (int i = 0; i <= n; ++i)
    {
      // n 回コイントスした状態で，どの回数のカウントが行われている状態が一番和が大きいか見る
      answer = max(answer, dp[n][i]);
    }

  cout << answer << endl;

  return 0;
}
