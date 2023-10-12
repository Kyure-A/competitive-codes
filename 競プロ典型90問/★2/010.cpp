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
  vector<int> c(n + 1);
  vector<int> p(n + 1);

  rep(i, n) cin >> c[i + 1] >> p[i + 1];

  vector<int> sum_1(n + 1);
  vector<int> sum_2(n + 1);

  for (int i = 0; i < n; ++i)
    {
      if (c[i + 1] == 1)
	{
	  sum_1[i + 1] = sum_1[i] + p[i + 1];
	  sum_2[i + 1] = sum_2[i];
	}

      else if (c[i + 1] == 2)
	{
	  sum_1[i + 1] = sum_1[i];
	  sum_2[i + 1] = sum_2[i] + p[i + 1];
	}
    }

  int q; cin >> q;
  q++;
  while (--q)
    {
      int l, r; cin >> l >> r;
      cout << sum_1[r] - sum_1[l - 1] << " " <<  sum_2[r] - sum_2[l - 1] << endl;
    }
  

  return 0;
}
