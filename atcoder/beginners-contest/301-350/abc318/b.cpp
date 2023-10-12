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
  
  int n; cin >> n;
  vector<vector<char>> grid(101, vector<char>(101, '.'));

  while (n--)
    {
      int a, b, c, d; cin >> a >> b >> c >> d;
      
      for (int i = a; i <= b; ++i)
	{
	  for (int j = c; j <= d; ++j)
	    {
	      grid[j][i] = '#';
	    }
	}
    }

  int answer = 0;
  
  for (int i = 0; i <= 100; ++i)
    {
      for (int j = 0; j <= 100; ++j)
	{
	  if (grid[i][j] == '#') answer++;
	}
    }

  cout << answer << endl;
  
  return 0;
}
