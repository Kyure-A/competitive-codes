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

  int n, d; cin >> n >> d;
  vector<int> t(n); rep(i, n) cin >> t[i];

  for (int i = 1; i < n; ++i)
    {
      if (t[i] - t[i - 1] <= d)
	{
	  cout << t[i] << endl;
	  return 0;
	}
    }

  cout << -1 << endl;

  return 0;
}
