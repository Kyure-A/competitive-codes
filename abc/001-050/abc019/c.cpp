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
  set<long long> x;

  for (int i = 0; i < n; ++i)
    {
      long long a; cin >> a;

      while (!(a % 2))
	{
	  a /= 2;
	}

      x.insert(a);
    }

  cout << x.size() << endl;

  return 0;
}
