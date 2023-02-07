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

  string n; cin >> n;
  int x = n.size();

  long long sum = 0;
  
  for (int i = 0; i < x; ++i)
    {
      // スコープがかなり謎で、 a %= _MOD から sum %= _MOD; の行を if 文の外に出すと全部 a と b が 0 になってしまう 謎だ
      if (i == 0)
	{
	  long long a = stoll(n.substr(i, x - i)) % _MOD - (long long)pow(10, x - i - 1) % _MOD + 1;
	  long long b = a + 1;
	  
	  a %= _MOD;
	  b %= _MOD;

	  sum += a * b / 2;
	  sum %= _MOD;
	}
	
      else
	{
	  string tmp = "";
	  
	  for (int j = 1; j <= x - i; ++j)
	    {
	      tmp += "9";
	    }
	  
	  long long a = stoll(tmp) % _MOD - (long long)pow(10, x - i - 1) % _MOD + 1;
	  long long b = a + 1;

	  a %= _MOD;
	  b %= _MOD;

	  sum += a * b / 2;
	  sum %= _MOD;
	}
    }

  cout << sum << endl;

  return 0;
}
