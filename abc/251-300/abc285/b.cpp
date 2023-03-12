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
  string s; cin >> s;
  s = " " + s; // 1 indexed
  vector<int> result(n + 1);
  
  for (int i = 1; i <= n - 1; ++i)
    {
      int max_l = 0;
      bool flag = false;
      
      for (int l = 0; l + i <= n; ++l)
	{
	  for (int k = 1; k <= l; ++k)
	    {
	      if (s[k] == s[k + i]) flag = true;
	      if (flag) break;
	    }
	  
	  max_l = l;
	  if (flag)
	    {
	      max_l--;
	      break;
	    }
	}

      result[i] = max_l;
      
    }

  for (int i = 1; i < n; ++i)
    {
      cout << result[i] << endl;
    }
  
  return 0;
}
