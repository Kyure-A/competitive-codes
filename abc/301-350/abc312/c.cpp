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
  
  int n, m; cin >> n >> m;
  vector<int> a(n); rep(i, n) cin >> a[i];
  vector<int> b(m); rep(i, m) cin >> b[i];
  
  sort(all(a)); sort(all(b));
  
  auto check = [&](int price) -> bool
  {
    int count = 0;

    for (int i = 0; i < m; ++i)
      {
	if (b[i] >= price) count++;
      }

    for (int i = 0; i < n; ++i)
      {
	if (a[i] <= price) count--;
      }

    return (count <= 0);
  };

  auto bsearch = [&]() -> int
  {
    int l = -1;
    int r = 1e9;
    
    while (abs(r - l) > 1)
      {
	int mid = (r + l) / 2;

	if (check(mid)) r = mid;
	else l = mid;
      }

    return r;
  };

  cout << bsearch() << endl;
  
  return 0;
}
