/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/modint>
// #include <boost/multiprecision/cpp_int.hpp>
/* ------------------------------  using  ------------------------------ */
using namespace std;
// using namespace atcoder;
// using namespace boost::multiprecision;
/* ------------------------------  define ------------------------------ */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

bool check(long long x, long long n, long long m)
{
  long long count = 0;
  
  for (long long i = 1; i <= n; i++)
    {
      count += min(n, x / i);
    }
  
  return count >= m;
}

signed main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  long long n, m; cin >> n >> m;

  long long left = 1, right = n * n;
  
  while (left <= right)
    {
      long long mid = (left + right) / 2;
      if (check(mid, n, m)) right = mid - 1;
      else left = mid + 1;
    }

  if (left > n * n) cout << "-1" << endl;
  else cout << left << endl;
  return 0;
}
