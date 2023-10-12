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
  
  // input
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1), c(n + 1); rep(i, n) cin >> a[i + 1] >> b[i + 1] >> c[i + 1];
  // exception i = 0
  a[0] = b[0] = c[0] = -1e9;
  
  // initialize dp table: dp[day][vacation] = vacation_happiness
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));
  dp[0] = {(int)-1e9};
  dp[1][0] = a[1];
  dp[1][1] = b[1];
  dp[1][2] = c[1];

  
  // morau dp
  for (int day = 2; day <= n; ++day)
    {
      for (int vac = 0; vac <= 2; ++vac)
	{
	  if (vac == 0) // a
	    {
	      dp[day][vac] = max(dp[day - 1][1] + a[day], dp[day - 1][2] + a[day]);
	    }
	  
	  else if (vac == 1) // b
	    {
	      dp[day][vac] = max(dp[day - 1][0] + b[day], dp[day - 1][2] + b[day]);
	    }

	  else if (vac == 2) // c
	    {
	      dp[day][vac] = max(dp[day - 1][0] + c[day], dp[day - 1][1] + c[day]);
	    }
	}
    }

  cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << "\n";
  
  return 0;
}
