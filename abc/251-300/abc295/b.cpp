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

  int r, c; cin >> r >> c;
  vector<string> b(r);
  for (int i = 0; i < r; ++i)
    {
      cin >> b[i];
    }

  for (int r1 = 0; r1 < r; ++r1)
    {
      for (int c1 = 0; c1 < c; ++c1)
	{
	  for (auto ch : {'1', '2', '3', '4', '5', '6', '7', '8', '9'})
	    {
	      if (b[r1][c1] == ch)
		{
		  int power = ctoi(ch);
		  b[r1][c1] = '.';
		  
		  for (int r2 = 0; r2 < r; ++r2)
		    {
		      for (int c2 = 0; c2 < c; ++c2)
			{
			  if (abs((r1 + 1) - (r2 + 1)) + abs((c1 + 1) - (c2 + 1)) <= power)
			    {
			      if (b[r2][c2] == '#')
				{
				  b[r2][c2] = '.';
				}
			    }
			}
		    }
		}
	    }
	}
    }

  for (int i = 0; i < r; ++i)
    {
      cout << b[i] << endl;
    }

  return 0;
}
