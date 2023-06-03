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

  int N, W; cin >> N >> W;
  vector<int> w(N + 1), v(N + 1); rep(i, N) cin >> w[i + 1] >> v[i + 1];
  
  // dp[N][W] = value
  vector<vector<int>> dp(N + 1, vector<int>(W + 1));

  for (int i = 0; i <= W; ++i)
    {
      dp[0][i] = 0;
    }
  
  for (int i = 1; i <= N; ++i)
    {
      for (int weight = 0; weight <= W; ++weight)
	{
	  if (weight - w[i] >= 0)
	    {
	      dp[i][weight] = max(dp[i - 1][weight], dp[i - 1][weight - w[i]] + v[i]); 
	    }
	  else dp[i][weight] = dp[i - 1][weight];
	}
    }

  cout << dp[N][W] << endl;
  
  return 0;
}
