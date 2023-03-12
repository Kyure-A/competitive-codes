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

  int n; cin >> n;
  vector<int> a(n); rep(i, n) cin >> a[i];
  int m; cin >> m;
  vector<int> dp((int)1e5 + 1, 0);
  dp[0] = 1; 
  vector<int> b(m); rep(i, m) {cin >> b[i]; dp[b[i]] = -1;}
  int x; cin >> x;

  for (int i = 0; i <= (int)1e5; ++i)
    {
      if (dp[i] < 0) continue;
      for (int j = 0; j < n; ++j)
	{
	  if (i + a[j] <= (int)1e5)
	    {
	      if (dp[i] == -1) continue;
	      else if (dp[i + a[j]] == -1) continue;
	      else dp[i + a[j]] = 1;
	    }
	}
    }
  
  if (dp[x] == 1) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  
  return 0;
}
  
