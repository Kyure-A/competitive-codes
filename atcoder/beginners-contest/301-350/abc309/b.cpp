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
constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<string> a(n); rep(i, n) cin >> a[i];

  int count = 0;
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (i == 0 and j == 0)
	    {
	      cout << a[1][0];
	      count++;
	    }
	  
	  else if (i == 0 and j == n - 1)
	    {
	      cout << a[0][n - 2];
	      count++;
	    }

	  else if (i == n - 1 and j == 0)
	    {
	      cout << a[n - 1][1];
	      count++;
	    }
	  
	  else if (j == n - 1 and i == n - 1)
	    {
	      cout << a[n - 2][n - 1];
	      count++;
	    }


	  else if (i == 0 and j != 0 and j != n - 1)
	    {
	      cout << a[0][j - 1];
	      count++;
	    }

	  else if (j == 0 and i != n - 1 and i != 0)
	    {
	      cout << a[i + 1][0];
	      count++;
	    }
	  
	  else if (i == n - 1 and j != 0 and j != n - 1)
	    {
	      cout << a[n - 1][j + 1];
	      count++;
	    }

	  else if (j == n - 1 and i != n - 1 and i != 0)
	    {
	      cout << a[i - 1][n - 1];
	      count++;
	    }

	  else
	    {
	      cout << a[i][j];
	      count++;
	    }

	  if (count == n)
	    {
	      cout << endl;
	      count = 0;
	    }
	}
    }
  
  return 0;
}
