#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
/* ------------------------------ code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, x; cin >> n >> x;
  multiset<int> a; rep(i, n) {int x; cin >> x; a.emplace(x);}

  for (int y : a)
    {
      if (x - y >= 0)
	{
	  x -= y;
	  a.erase(a.find(y));
	  a.emplace(0);
	}
    }
  
  if (x > 0) cout << a.count(0) - 1 << endl;
  else cout << a.count(0) << endl;

  return 0;
}
