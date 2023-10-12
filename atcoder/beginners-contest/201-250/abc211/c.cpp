/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/all>
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
/* ------------------------------  const  ------------------------------ */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;
/* ------------------------------  code   ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string s; cin >> s;
  
  int count = 0;
  for (int i = 0; i < (int)s.size(); ++i)
    {
      if (i + 8 > (int)s.size()) break;
      else
	{
	  if (s[i] == 'c' and s[i + 1] == 'h' and s[i + 2] == 'o' and s[i + 3] == 'k' and s[i + 4] == 'u' and s[i + 5] == 'd' and s[i + 6] == 'a' and s[i + 7] == 'i')
	    {
	      count++;
	      count %= MOD;
	    }
	}
    }

  cout << count << "\n";
  
  return 0;
}
