#include <bits/stdc++.h>
using namespace std;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
using int64 = long long;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<int> a(m); rep(i, m) cin >> a[i];

  for (int i = 1; i <= n; ++i)
    {
      auto hanabi = lower_bound(a.begin(), a.end(), i);
      cout << *hanabi - i << endl;
    }
  
  return 0;
}
