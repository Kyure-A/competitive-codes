#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
/* ------------------------------ code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  vector<string> s(h); rep(i, h) cin >> s[i];

  for (int i = 0; i < h; ++i)
    {
      for (int j = 1; j < w; ++j)
	{
	  if (s[i][j - 1] == 'T' and s[i][j] == 'T')
	    {
	      s[i][j - 1] = 'P';
	      s[i][j] = 'C';
	    }
	}
    }

  for (auto x : s) cout << x << endl;

  return 0;
}
