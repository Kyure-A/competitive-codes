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

  int h, w; cin >> h >> w;
  vector<string> c(h); rep(i, h) cin >> c[i];

  map<pair<int, int>, bool> sharp;
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  if (c[i][j] == '#') sharp[make_pair(i, j)] = true;
	}
    }

  int n = min(h, w);

  vector<int> s(n + 1, 0);

  for (int d = 1; d <= n; ++d)
    {
      for (int i = 0; i < h; ++i)
	{
	  for (int j = 0; j < w; ++j)
	    {
	      if (i + d < h and
		  j + d < w and
		  i - d >= 0 and
		  j - d >= 0 and
		  i + n + 1 < h and
		  j + n + 1 < w and
		  i - n - 1 >= 0 and
		  j - n - 1 >= 0 and
		  sharp[make_pair(i, j)] and
		  sharp[make_pair(i + d, j + d)] and
		  sharp[make_pair(i + d, j - d)] and
		  sharp[make_pair(i - d, j + d)] and
		  sharp[make_pair(i - d, j - d)] and
		  (!sharp[make_pair(i + n + 1, j + n + 1)] or
		   !sharp[make_pair(i + n + 1, j - n - 1)] or
		   !sharp[make_pair(i - n - 1, j + n + 1)] or
		   !sharp[make_pair(i - n - 1, j - n - 1)]))
		{
		  s[d]++;
		}
	    }
	}
    }

  for (int d = 1; d < n; ++d)
    {
      s[d] -= s[d + 1];
    }

  for (int d = 1; d <= n; ++d)
    {
      cout << s[d] << " ";
    }

  return 0;
}
