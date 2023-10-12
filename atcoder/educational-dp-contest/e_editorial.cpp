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

  int n, max_weight; cin >> n >> max_weight;
  vector<int> w(n + 1), v(n + 1); rep(i, n) cin >> w[i + 1] >> v[i + 1];
  
  // initialize dp table: dp[i][value] = weight
  // val no max wo motomeru
  vector<vector<int>> dp(n + 1, vector<int>(n * 1010 + 1, 1e9));
  dp[0][0] = 0;
  
  for (int i = 0; i < n; ++i)
    {
      for (int va = 0; va <= n * 1010 + 1; ++va)
	{
	  dp[i + 1][va] = min(dp[i + 1][va], dp[i][va]);
	  dp[i + 1][va] = min(dp[i + 1][va + v[i]], dp[i][va] + w[i]);
	}
    }

  int answer = 0;
  
  for (int va = 0; va <= n * 1010 + 1; ++va)
    {
      if (dp[n][va] <= max_weight) answer = max(answer, va);
    }

  cout << answer << endl;

  return 0;
}
