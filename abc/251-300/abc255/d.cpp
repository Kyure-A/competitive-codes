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

  int n, q; cin >> n >> q;
  vector<int> a(n); rep(i, n) cin >> a[i];
  sort(all(a));
  
  while (q--)
    {
      int x; cin >> x;
      int vecx = x * a.size(); 
      auto itr = lower_bound(all(a), x);
      long long sum_min = accumulate(a.begin(), itr, 1ll);
      itr++;
      long long sum_max = accumulate(itr, a.end(), 1ll);
      cout << abs(vecx - sum_min) + abs(vecx - sum_max) << endl;
    }

  return 0;
}
