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
  int n;
  cin >> n;
  
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  int q;
  cin >> q;
  
  vector<int> l(q);
  vector<int> r(q);
  rep(i,n){cin >> l[i] >> r[i];}

  vector<vector<int>> sum(2, vector<int>(n));

  // 1 banme = atari 1 or hazure 0
  
  if (a[0] == 1)
    {
      sum[0][0] = 0;
      sum[1][0] = 1;
    }

  else
    {
      sum[0][0] = 1;
      sum[1][0] = 0;
    }
  
  for (int i = 1; i < n; ++i)
    {
      if (a[i] == 1)
	{
	  sum[0][i] = 0 + sum[0][i - 1];
	  sum[1][i] = 1 + sum[1][i - 1];
	}

      else
	{
	  sum[0][i] = 1 + sum[0][i - 1];
	  sum[1][i] = 0 + sum[1][i - 1];
	}
    }

  for (int i = 0; i < q; ++i)
    {
      int result = (sum[1][r[i] - 1] - sum[1][l[i] - 1]) - (sum[0][r[i] - 1] - sum[0][l[i] - 1]);
      if (result == 0) cout << "draw" << endl;
      else if (result > 0) cout << "win" << endl;
      else if (result < 0) cout << "lose" << endl;
    }

  return 0;
}
