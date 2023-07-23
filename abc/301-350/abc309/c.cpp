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
  
  long long n, k; cin >> n >> k;
  vector<long long> a(n), b(n); rep(i, n) cin >> a[i] >> b[i];
  map<long long, long long> medicine;

  for (int i = 0; i < n; ++i)
    {
      medicine[a[i]] += b[i];
    }
  
  sort(all(a), greater<long long>());

  for (int i = n; i >= 1; --i)
    {
      medicine[a[i - 1]] += medicine[a[i]];
    }
  
  long long day = a[0];

  sort(all(a));

  for (int i = 0; i < n; ++i)
    {
      cout << a[i] << ": " << medicine[a[n - 1 - i]]  << endl;
    }
  
  for (int i = 0; i < n - 1; ++i)
    {
      day = a[i];

      if (medicine[a[i]] <= k)
	{
	  if (a[i] != 1) day = a[i - 1] + 1;
	  break;
	}
    }

  cout << day + 1 << endl;
  
  return 0;
}
