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

int d (int n)
{
  return log10(n)+1;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int64 a, b, x; cin >> a >> b >> x;

  int64 left = 0, right = 1e9 + 1;
  
  while (left <= right)
    {
      int64 mid = (left + right) / 2;
      if (a * mid + b * d(mid) <= x) left = mid + 1;
      else right = mid - 1;
    }

  cout << left << endl;

  return 0;
}
