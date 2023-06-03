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

  int n, x; cin >> n >> x;
  vector<int> a(n + 1), b(n + 1); rep(i, n) cin >> a[i + 1] >> b[i + 1];

  // initialize dp table: dp[coin][value] = true : false
  vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
  dp[0][0] = true;

  for (int coin = 1; coin <= n; ++coin) // n <= 50
    {
      for (int value = 0; value <= x; ++value) // x <= 1e4
	{
	  for (int qt = 0; qt <= b[coin]; ++qt) // b[i] <= 50
	    {
	      if (value < a[coin] * qt)
		{
		  if (dp[coin - 1][value]) dp[coin][value] = true;
		}

	      if (value >= a[coin] * qt)
		{
		  if (dp[coin - 1][value - a[coin] * qt] == true or dp[coin - 1][value]) dp[coin][value] = true;
		}
	    }
	}
    }

  for (int coin = 0; coin <= n; ++coin)
    {
      if (dp[coin][x] == true)
	{
	  cout << "Yes" << endl;
	  return 0;
	}
    }

  cout << "No" << endl;

  return 0;
}
