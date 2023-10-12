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
  
  char chokudai[8] = {'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};
  // dp(i, j) = i 文字目までみて chokudai[0] .. chokudai[j]  が出ている数
  vector<vector<long long>> dp(n + 1, vector<long long>(256, 0));

  for (int i = 1; i <= n; ++i)
    {
      dp[i]['c'] = dp[i - 1]['c'];
      if (s[i - 1] == 'c') dp[i]['c']++;
    }
  
  for (int i = 1; i <= n; ++i)
    {
      for (int j = 0; j < 8; ++j)
	{
	  if (chokudai[j] == 'c') continue;
	  
	  dp[i][chokudai[j]] += dp[i - 1][chokudai[j]];
	  dp[i][chokudai[j]] %= MOD;
	  
	  if (chokudai[j] == s[i - 1])
	    {
	      dp[i][chokudai[j]] += dp[i - 1][chokudai[j - 1]] % MOD;
	      dp[i][chokudai[j]] %= MOD;
	    }
	}
    }

  cout << dp[n]['i'] % MOD << endl;

  return 0;
}
