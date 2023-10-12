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

  vector<int> in(n, 0);

  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      a--; b--;
      in[b]++;
    }

  vector<int> saikyo;
  
  for (int i = 0; i < n; ++i)
    {
      if (in[i] == 0) saikyo.push_back(i);
    }

  if (saikyo.size() == 1) cout << saikyo[0] + 1 << endl;
  else cout << -1 << endl;
  
  return 0;
}
