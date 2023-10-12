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
  vector<vector<char>> a(h, vector<char>(w)), b(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) cin >> b[i][j];
  
  int q = h * w + 1;

  int answer = 0;
  
  while (q--)
    {
      for (int i = ceil((double) h / 2); i < h; ++i)
	{
	  for (int j = ceil((double) w / 2); j < w; ++j)
	    {
	      if (i == h - 1 and j == w - 1)
		{
		  continue;
		}
	  
	      else if (i == h - 1)
		{
		  continue;
		}
	      else if (j == w - 1)
		{
		  continue;
		}
	      else
		{
		  swap(a[i][j], a[i + 1][j + 1]);
		}
	    }
	}
      
      bool flag = true;
      
      for (int i = 0; i < h; ++i)
	{
	  for (int j = 0; j < w; ++j)
	    {
	      if (a[i][j] != b[i][j]) flag = false;
	    }
	}

      cout << q << ": "<< endl;

      for (int i = 0; i < h; ++i)
	{
	  for (int j = 0; j < w; ++j)
	    {
	      cout << a[i][j];
	    }
	  cout << endl;
	}

      if (flag) answer++;
      
    }

  if (answer) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
