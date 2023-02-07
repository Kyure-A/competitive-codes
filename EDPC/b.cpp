/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int n, k; cin >> n >> k;
  vector<int> h(n + 1); rep(i, n) cin >> h[i + 1]; // 1 indexed
  
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 0;

  for (int i = 2; i <= n; ++i)
    {
      dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
      for (int j = 2; j <= k; ++j)
	{
	  if (i > j) dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
	}
    }

  cout << dp[n] << endl;

  return 0;
}
