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

// editorial

signed main ()
{
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  string s = " "; // s.size() == 2n
  string tmp; cin >> tmp;
  s += tmp;
  int q; cin >> q;

  bool flipped = false;
  
  for (int i = 1; i <= q; ++i)
    {
      int t, a, b; cin >> t >> a >> b;

      if (t == 1)
	{
	  if (flipped)
	    {
	      // 反転しているときは a, b の大小関係が逆転する
	      if (a <= n) a += n;
	      else a -= n;

	      if (b <= n) b += n;
	      else b -= n;
	    }
	  
	  swap(s[a], s[b]);
	}

      if (t == 2)
	{
	  flipped = !flipped;
	}
    }

  if (flipped) cout << s.substr(n + 1, n) << s.substr(1, n) << endl;
  else cout << s.substr(1, 2 * n) << endl;

  return 0;
}
