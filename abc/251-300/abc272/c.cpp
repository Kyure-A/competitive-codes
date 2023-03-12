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
  vector<int> a(n); rep(i, n) cin >> a[i];
  sort(all(a), greater<int>());

  long long max_odd = 0;
  int odd_count = 0;
  long long max_even = 0;
  int even_count = 0;
  
  for (int i = 0; i < (int)a.size(); ++i)
    {
      if (a[i] % 2 == 0 and even_count != 2)
	{
	  max_even += a[i];
	  even_count++;
	}
      else if (a[i] % 2 == 1 and odd_count != 2)
	{
	  max_odd += a[i];
	  odd_count++;
	}
    }

  if (even_count != 2 and odd_count != 2) cout << -1 << endl;
  else if (even_count == 2 and odd_count != 2) cout << max_even << endl;
  else if (even_count != 2 and odd_count == 2) cout << max_odd << endl;
  else cout << max(max_odd, max_even) << endl;

  return 0;
}
