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
constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, s; cin >> n >> s;

  struct card {
    int h;
    int t;
  };

  vector<card> cards(n + 1);

  for (int i = 1; i <= n; ++i)
    {
      int a, b; cin >> a >> b;
      cards[i] = {a, b};
    }

  // dp(i, j) = i 番目までのカードを選んだとき，表面に書かれた整数の和が j になるようなカードの置き方 (置けない場合は "")

  vector<vector<string>> dp(n + 1, vector<string>(s + 1, ""));
  
  
  for (int i = 1; i <= n; ++i)
    {
      for (int j = 0; j <= s; ++j)
	{
	  if (i != 0)
	    {
	      if (dp[i][j - cards[i].h] != "" and j - cards[i].h >= 0) dp[i][j] = dp[i - 1][j - cards[i].h] + "H";
	      if (dp[i][j - cards[i].t] != "" and j - cards[i].t >= 0) dp[i][j] = dp[i - 1][j - cards[i].t] + "T";
	    }

	  else
	    {
	      if (j - cards[i].h >= 0) dp[i][j] = dp[i - 1][j - cards[i].h] + "H";
	      if (j - cards[i].t >= 0) dp[i][j] = dp[i - 1][j - cards[i].t] + "T";
	    }
	}
    }

  string answer = dp[n][s];
  int sum = 0;

  if ((int)answer.size() != n)
    {
      cout << "No" << endl;
      return 0;
    }
  
  for (int i = 0; i < (int)answer.size(); ++i)
    {
      if (answer[i] == 'H') sum += cards[i + 1].h;

      else // if (answer[i] == 'T')
	sum += cards[i + 1].t;
    }

  if (sum == s)
    {
      cout << "Yes" << endl << answer << endl;
    }

  else cout << "No" << endl;
  
  return 0;
}
