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

  unsigned int x, y, z; cin >> x >> y >> z;
  string s; cin >> s;

  int n = s.size();
  
  // dp[i: CapsLock キーが押されているか][j 文字目まで] = j 文字目までの S の部分文字列に一致させるのに必要な最短の時間
  vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(n + 1, 0));
  dp[0][0] = dp[1][0] = 0;
  
  for (int i = 1; i <= n; ++i)
    {
      if (s[i - 1] == 'A')
	{
	  dp[0][i] = min(dp[0][i - 1] + y, dp[1][i - 1] + (x + z));
	  dp[1][i] = min(dp[1][i - 1] + x, dp[0][i - 1] + (y + z));
	}

      if (s[i - 1] == 'a')
	{
	  dp[0][i] = min(dp[0][i - 1] + x, dp[1][i - 1] + (y + z));
	  dp[1][i] = min(dp[1][i - 1] + y, dp[0][i - 1] + (x + z));
	}
    }

  cout << min(dp[0][n], dp[1][n]) << endl;

  return 0;
}
