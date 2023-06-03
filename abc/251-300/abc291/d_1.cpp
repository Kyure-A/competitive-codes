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
  vector<int> a(n), b(n); rep(i, n) cin >> a[i] >> b[i];

  // initialize dp table: dp[card][omote or ura] = {0 or 1}
  vector<vector<int>> dp(n, vector<int>(2));
  dp[0][0] = 1;
  dp[0][1] = 1;

  for (int i = 0; i < n - 1; ++i)
    {
      if (a[i] != a[i + 1])
	{
	  dp[i + 1][0] += dp[i][0];
	  dp[i + 1][0] %= _MOD;
	}
      
      if (a[i] != b[i + 1]) 
	{
	  dp[i + 1][1] += dp[i][0];
	  dp[i + 1][1] %= _MOD;
	}
      
      if (b[i] != a[i + 1])
	{
	  dp[i + 1][0] += dp[i][1];
	  dp[i + 1][0] %= _MOD;
	}

      if (b[i] != b[i + 1])
	{
	  dp[i + 1][1] += dp[i][1];
	  dp[i + 1][1] %= _MOD;
	}
    }

  long long answer = dp[n - 1][0] + dp[n - 1][1];
  answer %= _MOD;
  
  cout << answer << endl;
  
  return 0;
}
