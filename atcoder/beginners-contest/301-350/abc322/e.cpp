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
  
  int n, k, p; cin >> n >> k >> p;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(k));

  for (int i = 0; i < n; ++i)
    {
      cin >> c[i];
      for (int j = 0; j < k; ++j)
	{
	  cin >> a[i][j];
	}
    }

  
  
  return 0;
}
