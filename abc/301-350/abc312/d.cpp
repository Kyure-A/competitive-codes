#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/modint>
// using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.size();
  
  // j を '(' で + 1, ')' で - 1
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;

  auto pplus = [&](int i) -> void
  {
    for (int j = 0; j < n; ++j)
      {
	dp[i + 1][j + 1] += dp[i][j];
	dp[i + 1][j + 1] %= _MOD;
      }
  };

  auto pminus = [&](int i) -> void
  {
    for (int j = 0; j < n; ++j)
      {
	if (j - 1 < 0) continue;
	dp[i + 1][j - 1] += dp[i][j];
	dp[i + 1][j - 1] %= _MOD;
      }
  };

  for (int i = 0; i < n; ++i)
    {
      if (s[i] == '(')
	{
	  pplus(i);
	}
      
      else if (s[i] == ')')
	{
	  pminus(i);
	}
      
      else if (s[i] == '?')
	{
	  pplus(i);
	  pminus(i);
	}
    }
  
  cout << dp[n][0] % _MOD << endl;

  return 0;
}
