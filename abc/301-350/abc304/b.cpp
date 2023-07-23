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

  int n; cin >> n;

  if (n <= 1000 - 1) cout << n << endl;
  else if (n <= 10000 - 1) cout << floor(n / 10) * 10 << endl;
  else if (n <= 100000 - 1) cout << floor(n / 100) * 100 << endl;
  else if (n <= 1000000 - 1) cout << floor(n / 1000) * 1000 << endl;
  else if (n <= 10000000 - 1) cout << floor(n / 10000) * 10000 << endl;
  else if (n <= 100000000 - 1) cout << floor(n / 100000) * 100000 << endl;
  else if (n <= 1000000000 - 1) cout << floor(n / 1000000) * 1000000 << endl;

  return 0;
}
