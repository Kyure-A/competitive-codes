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
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
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

  int n; cin >> n;
  vector<vector<int>> vacation(n + 1, vector<int>(3));
  rep(i, n) rep(j, 3) cin >> vacation[i + 1][j];

  // dp
  vector<vector<int>> dp(n + 1, vector<int>(3));
  dp[1][0] = vacation[1][0];
  dp[1][1] = vacation[1][1];
  dp[1][2] = vacation[1][2];
  
  for (int i = 1; i <= n - 1; ++i)
    {
      dp[i + 1][0] += max(dp[i][1], dp[i][2]) + vacation[i + 1][0];
      dp[i + 1][1] += max(dp[i][0], dp[i][2]) + vacation[i + 1][1];
      dp[i + 1][2] += max(dp[i][0], dp[i][1]) + vacation[i + 1][2];
    }

  cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
  
  return 0;
}
