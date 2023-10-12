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

  int n, w; cin >> n >> w;
  vector<int> value_i(n + 1), weight_i(n + 1); rep(i, n) cin >> weight_i[i + 1] >> value_i[i + 1];

  // initialize dp table: dp[i (1 <= i <= n)][weight] = value
  vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));
  rep(i, w + 1) dp[0][i] = 0;

  long long answer = 0;
  
  for (int i = 1; i <= n; ++i)
    {
      for (int we = 0; we <= w; ++we)
	{
	  if (we - weight_i[i] >= 0) dp[i][we] = max(dp[i - 1][we], dp[i - 1][we - weight_i[i]] + value_i[i]); //  ここほぼ 部分和問題 なので思い出すといい
	  else dp[i][we] = dp[i - 1][we];

	  answer = max(dp[i][we], answer); // dp[n][w] が答えとは限らないっす
	}
    }

  cout << answer << endl; 

  return 0;
}
