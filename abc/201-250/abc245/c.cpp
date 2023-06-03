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

  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  // dp:
  // dp[i][0] = a_i - a_i+1 <= k, dp[i][1] = a_i - b_i+1 <= k,
  // dp[i][2] = b_i - a_i+1 <= k, dp[i][3] = b_i - a_i+1 <= k;
  vector<vector<bool>> dp(n, vector<bool>(4, false));
  rep(i, 4) dp[0][i] = true;
  
  for (int i = 0; i < n - 1; ++i)
    {
      if (abs(a[i] - a[i + 1]) <= k and (dp[i][0] or dp[i][2])) dp[i + 1][0] = true;
      if (abs(a[i] - b[i + 1]) <= k and (dp[i][0] or dp[i][2])) dp[i + 1][1] = true;
      if (abs(b[i] - a[i + 1]) <= k and (dp[i][1] or dp[i][3])) dp[i + 1][2] = true;
      if (abs(b[i] - b[i + 1]) <= k and (dp[i][1] or dp[i][3])) dp[i + 1][3] = true;
    }

  if (dp[n - 1][0] or dp[n - 1][1] or dp[n - 1][2] or dp[n - 1][3]) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
