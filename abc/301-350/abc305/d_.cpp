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

class BIT
{
public:

  BIT() = default;

  // 長さ size の数列で初期化
  explicit BIT(size_t size)
    : m_bit(size + 1) {}

  // 数列で初期化
  explicit BIT(const std::vector<long long>& v)
    : BIT(v.size())
  {
    for (int i = 0; i < v.size(); ++i)
      {
	add((i + 1), v[i]);
      }
  }

  // 閉区間 [1, r] の合計を返す (1-based indexing)
  long long sum(int r) const
  {
    long long ret = 0;

    for (; 0 < r; r -= (r & -r))
      {
	ret += m_bit[r];
      }

    return ret;
  }

  // 閉区間 [l, r] の合計を返す (1-based indexing)
  long long sum(int l, int r) const
  {
    return (sum(r) - sum(l - 1));
  }

  // 数列の i 番目の要素を加算 (1-based indexing)
  void add(int i, long long value)
  {
    for (; i < m_bit.size(); i += (i & -i))
      {
	m_bit[i] += value;
      }
  }

private:

  std::vector<long long> m_bit;
};

// Binary Indexed Tree (1.2 区間加算対応)
// 1-based indexing
class BIT_RAQ
{
public:

  BIT_RAQ() = default;

  explicit BIT_RAQ(size_t size)
    : m_bit0(size)
    , m_bit1(size) {}

  explicit BIT_RAQ(const std::vector<long long>& v)
    : m_bit0(v)
    , m_bit1(v.size()) {}

  // 閉区間 [1, r] の合計を返す (1-based indexing)
  long long sum(int r) const
  {
    return (m_bit0.sum(r) + m_bit1.sum(r) * r);
  }

  // 閉区間 [l, r] の合計を返す (1-based indexing)
  long long sum(int l, int r) const
  {
    return (sum(r) - sum(l - 1));
  }

  // 数列の i 番目の要素を加算 (1-based indexing)
  void add(int i, long long value)
  {
    m_bit0.add(i, value);
  }

  // 閉区間 [l, r] の要素を加算 (1-based indexing)
  void add(int l, int r, long long value)
  {
    m_bit0.add(l, (-value * (l - 1)));
    m_bit0.add((r + 1), (value * r));
    m_bit1.add(l, value);
    m_bit1.add((r + 1), -value);
  }

private:

  BIT m_bit0;

  BIT m_bit1;
};

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n + 1); rep(i, n) cin >> a[i + 1];
  BIT_RAQ bit(1e6 * 3);

  for (int i = 1; i <= (n - 1) / 2; ++i)
    {
      int l = a[2 * i];
      int r = a[2 * i + 1];
      bit.add(l, r, 1);
    }
  
  int q; cin >> q;

  while (q--)
    {
      int l, r; cin >> l >> r;
      cout << bit.sum(l, r) << endl;
    }

  return 0;
}
