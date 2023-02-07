/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
typedef long long i64;
typedef long long int64;
typedef long long ll;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, w; cin >> n >> w;
  vector<int> weight(n), value(n);
  rep(i, n) cin >> weight[i] >> value[i];
  vector<vector<long long>> dp(n + 1, vector<long long>(w + 1));

  for (int i = 0; i <= w; ++i)
    {
      dp[0][i] = 0;
    }

  for (int i = 1; i <= n; ++i)
    {
      for (int W = 0; W <= w; ++W)
	{
	  if (W - weight[i] >= 0) dp[i][W] = max(dp[i - 1][W], dp[i - 1][W - weight[i]] + value[i]);
	  else dp[i][W] = dp[i - 1][W];
	}
    }

  cout << dp[n][w] << endl;
  

  return 0;
}
