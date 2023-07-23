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

  struct dish {
    long long poisonuous;
    long long deliciousness;
  };
  
  int n; cin >> n;
  vector<dish> course(n + 1); rep(i, n) cin >> course[i + 1].poisonuous >> course[i + 1].deliciousness;

  // dp[i: 高橋くんがお腹を壊しているか][j: 高橋くんが提供された j 番目までの料理] = j 番目までの料理の中で食べた料理の美味しさの総和
  vector<vector<long long>> dp(2, vector<long long>(n + 1, 0));
  dp[0][0] = 0; dp[1][0] = 0;
  
  for (int i = 1; i <= n; ++i)
    {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[1][i - 1];
      
      if (course[i].poisonuous == 0)
	{
	  dp[0][i] = max(dp[0][i - 1], max(dp[0][i - 1] + course[i].deliciousness, dp[1][i - 1] + course[i].deliciousness));
	}

      if (course[i].poisonuous == 1)
	{
	  dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + course[i].deliciousness);
	}
    }

  cout << max(dp[0][n], dp[1][n]) << endl;
  
  return 0;
}
