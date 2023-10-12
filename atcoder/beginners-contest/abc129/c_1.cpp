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

  int n, m; cin >> n >> m;
  vector<int> a(m); rep(i, m) cin >> a[i];
  
  // dp table
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  rep(i, m) dp[a[i]] = -1;

  for (int i = 0; i <= n; ++i)
    {
      if (i + 1 <= n and dp[i] != -1 and dp[i + 1] != -1)
	{
	  dp[i + 1] += dp[i];
	  dp[i + 1] %= MOD;
	}

      if (i + 2 <= n and dp[i] != -1 and dp[i + 2] != -1)
	{
	  dp[i + 2] += dp[i];
	  dp[i + 2] %= MOD;
	}
    }

  cout << dp[n] << endl;
  
  return 0;
}
