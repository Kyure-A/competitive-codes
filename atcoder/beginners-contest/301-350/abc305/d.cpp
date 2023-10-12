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

template <typename T>
struct BIT {
  int n;             // 要素数
  vector<T> bit[2];  // データの格納先
  BIT(int n_) { init(n_); }
  void init(int n_) {
    n = n_ + 1;
    for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
  }
  void add_sub(int p, int i, T x) {
    for (int idx = i; idx < n; idx += (idx & -idx)) {
      bit[p][idx] += x;
    }
  }
  void add(int l, int r, T x) {  // [l,r) に加算
    add_sub(0, l, -x * (l - 1));
    add_sub(0, r, x * (r - 1));
    add_sub(1, l, x);
    add_sub(1, r, -x);
  }
  T sum_sub(int p, int i) {
    T s(0);
    for (int idx = i; idx > 0; idx -= (idx & -idx)) {
      s += bit[p][idx];
    }
    return s;
  }
  T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n); rep(i, n) cin >> a[i];
  BIT<long long> bit(1e6);

  for (int i = 1; i <= (n - 1) / 2; ++i)
    {
      int l = a[2 * i - 1];
      int r = a[2 * i];
      bit.add(l, r + 1, 1ll);
    }
  
  int q; cin >> q;

  while (q--)
    {
      int l, r; cin >> l >> r;
      cout << bit.sum(r) - bit.sum(l) << endl;
    }

  return 0;
}
