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
  
  if (n == 1)
    {
      cout << 360 - a[0] << endl;
      return 0;
    }
  
  vector<int> pizza;
  pizza.push_back(a[0]);
  
  for (int i = 1; i < n; ++i)
    {
      pizza.push_back((a[i] + pizza[i - 1]) % 360);
    }

  pizza.push_back(360);
  
  int ans = 0;
  
  sort(all(pizza));
  
  for (int i = 1; i < n; ++i)
    {
      ans = max(ans, pizza[i] - pizza[i - 1]);
    }

  cout << ans << endl;
  
  return 0;
}
