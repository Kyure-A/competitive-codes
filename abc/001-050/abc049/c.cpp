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

string solve (string s)
{
  string rs;
  reverse_copy(s.begin(), s.end(), back_inserter(rs));
  string t;
  vector<string> ddee = {"maerd", "remaerd" ,"esare", "resare"};
  for (int i = 0; i < (int)s.size() - 2; ++i)
    {
      if (rs[i] == 'm')
	{
	  t += ddee[0];
	  i += 4;
	}
      
      else if (rs[i] == 'e')
	{
	  t += ddee[2];
	  i += 4;
	}
      
      else if (rs[i] == 'r')
	{
	  if (rs[i + 2] == 'm')
	    {
	      t += ddee[1];
	      i += 6;
	    }
	  
	  else if (rs[i + 2] == 's')
	    {
	      t += ddee[3];
	      i += 5;
	    }
	}
      
      if (!(i < (int)s.size() - 2))
	{
	  if (rs == t) return "YES";
	  else return "NO";
	}
    }
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s; cin >> s;
  cout << solve(s) << endl;
  
  return 0;
}
