/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all>
// using namespace atcoder

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
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int n, y;
  cin >> n >> y;

  bool broke = false;

  int osatu[3];
  osatu[0] = -1;
  osatu[1] = -1;
  osatu[2] = -1;
  
  for (int i = 0; i <= n; ++i)
    {
      for (int j = 0; j <= n - i; ++j)
	{
	  if (10000 * i + 5000 * j + 1000 * (n - i - j) == y)
	    {
	      osatu[0] = i;
	      osatu[1] = j;
	      osatu[2] = n - i - j;
	    }
	}
    }

  cout << osatu[0] << " " << osatu[1] << " " << osatu[2] << endl;
  
  
  return 0;
}
