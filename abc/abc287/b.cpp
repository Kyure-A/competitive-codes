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

  int n, m; cin >> n >> m;
  vector<string> s(n); rep(i, n) cin >> s[i];
  vector<string> t(m); rep(i, m) cin >> t[i];

  int count = 0;
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
	{
	  if (s[i].substr(3, 3) == t[j])
	    {
	      count++;
	      break;
	    }
	}
    }

  cout << count << endl;

  return 0;
}
