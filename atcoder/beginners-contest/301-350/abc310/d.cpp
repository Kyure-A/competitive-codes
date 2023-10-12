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
  
  int n, t, m; cin >> n >> t >> m;
  
  vector<int> a(m), b(m);
  rep(i, n)
    {
      cin >> a[i] >> b[i];
      a[i]--; b[i]--;
    }
  
  vector<vector<bool>> kenaku(n, vector<bool>(n, false));

  rep(i, n)
    {
      kenaku[a[i]][b[i]] = true;
      kenaku[b[i]][a[i]] = true;
    }

  int count = 0;
  
  return 0;
}
