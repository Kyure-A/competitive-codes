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
  
  long long n, d, p; cin >> n >> d >> p;
  vector<long long> f(n); rep(i, n) cin >> f[i];
  sort(all(f), greater<int>());
  long double oneday = p / d;
  int count = 0;

  for (int i = 0; i < n; ++i)
    {
      if (oneday < f[i])
	{
	  count++;
	  f[i] = 0;
	}
    }

  long long result = accumulate(all(f), 0ll) + ceil(count / d) * p;
  
  cout << result << endl;
    
  return 0;
}
