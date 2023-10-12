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
  
  long long a, b, c, d; cin >> a >> b >> c >> d;
  // a + b * i <= (c * i * d)

  for (int i = 0; i < 1000000; ++i)
    {
      if (a + b * i <= c * i * d)
	{
	  cout << i << endl;
	  return 0;
	}
    }

  cout << -1 << endl;

  return 0;
}
