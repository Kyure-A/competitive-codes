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

signed mystoi (string s)
{
  int result;
  if (s != "") result = stoi(s);
  else result = -1;

  return result;
}

signed main ()
{
  string n; cin >> n;

  int score = 10000;
  
  for (int bit = 0; bit < (1 << n.size()); ++bit)
    {
      string s = "";
      
      for (int i = 0; i < (int)n.size(); ++i)
	{
	  if (bit & (1 << i))
	    {
	      s += n[i];
	    }
	}

      int result = mystoi(s);

      if (result % 3 == 0) score = min(score, (int)n.size() - (int)s.size());
    }

  if (score == 10000) cout << -1 << endl;
  else cout << score << endl;

  return 0;
}
