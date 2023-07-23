#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/modint>
// using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<int> p(n), c(n); 
  vector<vector<int>> f(n);
  vector<map<int, int>> f_exist(n);
  
  for (int i = 0; i < n; ++i)
      {
	cin >> p[i] >> c[i];

	for (int j = 0; j < c[i]; ++j)
	  {
	    int f_j; cin >> f_j;
	    f[i].push_back(f_j);
	    f_exist[i][f_j] = 1;
	  }
      }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  bool flag[3] = {false};
	  
	  if (i == j) continue;
	  
	  if (p[i] >= p[j]) flag[0] = true;
	  
	  if (p[i] > p[j]) flag[1] = true;

	  for (int k = 0; k < c[j]; ++k)
	    {
	      // cout << "f[" << j << "][" << k << "]" << f[j][k] << endl;
	      if (!f_exist[i][f[j][k]]) flag[1] = true;
	    }
	  
	  flag[2] = true;
	  for (int k = 0; k < c[i]; ++k)
	    {
	      // cout << "f[" << i << "][" << k << "]" << f[i][k] << endl;
	      if (!f_exist[j][f[i][k]])
		{
		  flag[2] = false;
		}
	    }

	  if (flag[0] and flag[1] and flag[2])
	    {
	      cout << "Yes" << endl;
	      return 0;
	    }
	}
    }

  cout << "No" << endl;
  
  return 0;
}
