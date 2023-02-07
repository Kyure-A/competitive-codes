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
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


#define int long long

signed main ()
{
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  vector<string> s_val(n + 1); 
  s_val[0] = s;
  
  for (int i = 1; i <= n; ++i)
    {
      s_val[i] = s_val[i - 1].substr(1) + s_val[i - 1].substr(0, 1);
    }
  
  long long score = 1000000000000;
  int b_count = 0;
  
  for (int i = 0; i <= n; ++i)
    {
      for (int j = 0; j < n / 2; ++j)
	{
	  if (s_val[i][j] != s_val[i][n - 1 - j])
	    {
	      b_count++;
	    }
	}

      score = min(score, (b * b_count + a * i)); 
      
    }

  cout << score << endl;

  return 0;
}
