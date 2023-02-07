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

  int n; cin >> n;
  vector<int> a(n); rep(i, n) cin >> a[i];

  if (n != 1)
    {
      // 90 + 180 + 45 = 315
      // 195 = 150 + 45
      vector<int> pizza;

      int sum = 0;
  
      for (int i = 0; i < n; ++i)
	{
	  if (sum + a[i] < 360)
	    {
	      pizza.push_back(a[i]);
	      sum += a[i];
	    }
	  else
	    {
	      pizza.push_back(sum + a[i] - 360);
	      sum = 0;
	    }
	}
      
      vector<int> ansvec;
  
      for (int i = 0; i < n - 1; ++i)
	{
	  ansvec.push_back(a[i] - a[i + 1]);
	}

      sort(all(ansvec), greater<int>());

      cout << ansvec[0] << endl;
    }

  else cout << 360 - a[0] << endl;

  return 0;
}
