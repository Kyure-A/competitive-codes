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
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

// やることないからナイーブな解法を出して茶を濁します．
// ARC 003 C(https://atcoder.jp/contests/arc033/tasks/arc033_3) が似たような感じ（i 番目に大きいものを k 個求めればこの問題になる）
// だなあと思ったけれど，セグ木でやっても O(QKlog(N)) までしか削減できないため，Q = K = 10^5 みたいなケースで計算量が爆発四散する

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k, q; cin >> n >> k >> q;
  vector<long long> a(n, 0);
  
  while (q--)
    {
      int x, y; cin >> x >> y;
      x--;
      
      a[x] = y;
      
      auto b = a;
      sort(b.begin(), b.end(), greater<int>());
      
      long long sum = 0;
      
      for (int i = 0; i < k; ++i) sum += b[i];

      cout << sum << endl;
    }

  

  return 0;
}
