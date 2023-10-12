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

  int n, s; cin >> n >> s;
  vector<int> a(n + 1); rep(i, n) cin >> a[i + 1];
  // dp
  vector<vector<string>> dp(n + 1, vector<string>(s + 1, "No"));
  dp[0][0] = "Yes";
  
  for (int i = 1; i <= n; ++i)
    {
      for (int j = 0; j <= s; ++j)
	{
	  if (j < a[i])
	    {
	      dp[i][j] = dp[i - 1][j];
	    }

	  if (j >= a[i])
	    {
	      if (dp[i - 1][j] == "Yes" or dp[i - 1][j - a[i]] == "Yes")
		{
		  dp[i][j] = "Yes";
		}
	      
	      else dp[i][j] = "No";
	    }
	}
    }

  cout << dp[n][s] << endl;
  
  return 0;
}
