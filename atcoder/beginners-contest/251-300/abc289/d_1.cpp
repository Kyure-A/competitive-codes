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
  vector<int> a(n); rep(i, n) cin >> a[i];
  int m; cin >> m;
  vector<int> b(m); rep(i, m) cin >> b[i];
  int x; cin >> x;

  vector<string> dp(x + 1, "unseen");
  dp[0] = "seen";
  rep(i, m) dp[b[i]] = "ricecake";
  
  for (int i = 0; i <= x; ++i)
    {
      for (int j = 0; j < n and i + a[j] <= x; ++j)
	{
	  if (dp[i] == "seen" and dp[i + a[j]] == "unseen") dp[i + a[j]] = "seen";
	}
    }

  if (dp[x] == "seen") cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
