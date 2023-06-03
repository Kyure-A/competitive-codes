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
  string s; cin >> s;
  
  // initizlize dp table: dp[index][atcoder[j]];
  vector<vector<int>> dp(n, vector<int>(7, 0));
  
  for (int i = 0; i < n; ++i)
    {
      for (int atcoder = 0; atcoder < 7; ++atcoder)
	{
	  if (s[i] == 'a')
	    {
	      dp[i][0]++;
	    }
	  
	  else if (s[i] == 't')
	    {
	      
	    }

	  else if (s[i] == 'c')
	    {
	      
	    }

	  else if (s[i] == 'o')
	    {
	      
	    }

	  else if (s[i] == 'd')
	    {
	      
	    }

	  else if (s[i] == 'e')
	    {
	      
	    }

	  else if (s[i] == 'r')
	    {
	      
	    }
	}
    }
  
  return 0;
}
