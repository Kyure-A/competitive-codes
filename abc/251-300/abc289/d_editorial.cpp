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

// editorial

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n); rep(i, n) cin >> a[i];
  int m; cin >> m;
  vector<int> b(m); rep(i, m) cin >> b[i];
  int x; cin >> x;

  vector<int> dp(x + 1, 0), available(x + 1, 1);
  for (auto bb : b) available[bb] = 0;
  dp[0] = 1; 

  for (int i = 0; i <= x; ++i)
    {
      if (!available[i]) dp[i] = 0;
      else
	{
	  for (int j = 0; j < n; ++j) if (i >= a[j]) dp[i] |= dp[i - a[j]];
	}
    }
  
  if (dp[x] == 1) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  
  return 0;
}
  
