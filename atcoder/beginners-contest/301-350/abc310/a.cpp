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
  
  int n, p, q; cin >> n >> p >> q;
  vector<int> d(n); rep(i, n) cin >> d[i];
  int min_dish = 1e9;

  for (int i = 0; i < n; ++i)
    {
      min_dish = min(min_dish, d[i]);
    }

  if (p <= q + min_dish) cout << p << endl;
  else cout << q + min_dish << endl;
  
  return 0;
}
