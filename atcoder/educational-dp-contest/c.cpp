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
  int n; cin >> n;
  vector<int> dp(n + 1);
  vector<string> work(n + 1);
  
  // query
  for (int i = 1; i <= n; ++i)
    {
      int a, b, c; cin >> a >> b >> c;
      int maxWork = max(a, max(b, c));
      
      if (i == 1)
	{
	  dp[1] = maxWork;
	  if (maxWork == a) work[1] = "a";
	  else if (maxWork == b) work[1] = "b";
	  else if (maxWork == c) work[1] = "c";
	}

      else
	{
	  if (maxWork == a and work[i - 1] == "a")
	    {
	      if (b > c)
		{
		  dp[i] = max(dp[i], dp[i - 1] + b);
		  work[i] = "b";
		}
	      else
		{
		  dp[i] = max(dp[i], dp[i - 1] + c);
		  work[i] = "c";
		}
	    }

	  else if (maxWork == b and work[i - 1] == "b")
	    {
	      if (a > c)
		{
		  dp[i] = max(dp[i], dp[i - 1] + a);
		  work[i] = "a"; 
		}
	      else
		{
		  dp[i] = max(dp[i], dp[i - 1] + c);
		  work[i] = "c";
		}
	    }

	  else if (maxWork == c and work[i - 1] == "c")
	    {
	      if (b > a)
		{
		  dp[i] = max(dp[i], dp[i - 1] + b);
		  work[i] = "b";
		}
	      else
		{
		  dp[i] = max(dp[i], dp[i - 1] + a);
		  work[i] = "a";
		}
	    }

	  else
	    {
	      dp[i] = max(dp[i], dp[i - 1] + maxWork);
	      if (maxWork == a) work[i] = "a";
	      else if (maxWork == b) work[i] = "b";
	      else if (maxWork == c) work[i] = "c";
	    }
	  
	}
    }

  cout << dp[n] << endl;
  
  return 0;
  
}
