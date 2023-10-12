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

namespace inner {
 
  using i32 = int32_t;
  using u32 = uint32_t;
  using i64 = int64_t;
  using u64 = uint64_t;
 
  template <typename T>
  T gcd(T a, T b) {
    while (b) swap(a %= b, b);
    return a;
  }
 
  template <typename T>
  T inv(T a, T p) {
    T b = p, x = 1, y = 0;
    while (a) {
      T q = b / a;
      swap(a, b %= a);
      swap(x, y -= q * x);
    }
    assert(b == 1);
    return y < 0 ? y + p : y;
  }
 
  template <typename T, typename U>
  T modpow(T a, U n, T p) {
    T ret = 1 % p;
    for (; n; n >>= 1, a = U(a) * a % p)
      if (n & 1) ret = U(ret) * a % p;
    return ret;
  }
 
}  // namespace inner
 
namespace my_rand {
  using i64 = long long;
  using u64 = unsigned long long;
 
  // [0, 2^64 - 1)
  u64 rng() {
    static u64 _x =
      u64(chrono::duration_cast<chrono::nanoseconds>(
						     chrono::high_resolution_clock::now().time_since_epoch())
	  .count()) *
      10150724397891781847ULL;
    _x ^= _x << 7;
    return _x ^= _x >> 9;
  }
 
  // [l, r]
  i64 rng(i64 l, i64 r) {
    assert(l <= r);
    return l + rng() % (r - l + 1);
  }
 
  // [l, r)
  i64 randint(i64 l, i64 r) {
    assert(l < r);
    return l + rng() % (r - l);
  }
 
  // choose n numbers from [l, r) without overlapping
  vector<i64> randset(i64 l, i64 r, i64 n) {
    assert(l <= r && n <= r - l);
    unordered_set<i64> s;
    for (i64 i = n; i; --i) {
      i64 m = randint(l, r + 1 - i);
      if (s.find(m) != s.end()) m = r - i;
      s.insert(m);
    }
    vector<i64> ret;
    for (auto& x : s) ret.push_back(x);
    return ret;
  }
 
  // [0.0, 1.0)
  double rnd() { return rng() * 5.42101086242752217004e-20; }
 
  template <typename T>
  void randshf(vector<T>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) swap(v[i], v[randint(0, i + 1)]);
  }
 
}  // namespace my_rand
 
using my_rand::randint;
using my_rand::randset;
using my_rand::randshf;
using my_rand::rnd;
using my_rand::rng;
 
struct ArbitraryLazyMontgomeryModInt {
  using mint = ArbitraryLazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;
 
  static u32 mod;
  static u32 r;
  static u32 n2;
 
  static u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }
 
  static void set_mod(u32 m) {
    assert(m < (1 << 30));
    assert((m & 1) == 1);
    mod = m;
    n2 = -u64(m) % m;
    r = get_r();
    assert(r * mod == 1);
  }
 
  u32 a;
 
  ArbitraryLazyMontgomeryModInt() : a(0) {}
  ArbitraryLazyMontgomeryModInt(const int64_t &b)
    : a(reduce(u64(b % mod + mod) * n2)){};
 
  static u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }
 
  mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }
 
  mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }
 
  mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }
 
  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }
 
  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }
  bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  mint operator-() const { return mint() - mint(*this); }
 
  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
 
  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }
 
  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = ArbitraryLazyMontgomeryModInt(t);
    return (is);
  }
 
  mint inverse() const { return pow(mod - 2); }
 
  u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }
 
  static u32 get_mod() { return mod; }
};
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::mod;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::r;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::n2;
 
struct montgomery64 {
  using mint = montgomery64;
  using i64 = int64_t;
  using u64 = uint64_t;
  using u128 = __uint128_t;
 
  static u64 mod;
  static u64 r;
  static u64 n2;
 
  static u64 get_r() {
    u64 ret = mod;
    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;
    return ret;
  }
 
  static void set_mod(u64 m) {
    //assert(m < (1LL << 62));
    //assert((m & 1) == 1);
    mod = m;
    n2 = -u128(m) % m;
    r = get_r();
    //assert(r * mod == 1);
  }
 
  u64 a;
 
  montgomery64() : a(0) {}
  montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};
 
  static u64 reduce(const u128 &b) {
    return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
  }
 
  mint &operator+=(const mint &b) {
    if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }
 
  mint &operator-=(const mint &b) {
    if (i64(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }
 
  mint &operator*=(const mint &b) {
    a = reduce(u128(a) * b.a);
    return *this;
  }
 
  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }
 
  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }
  bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  mint operator-() const { return mint() - mint(*this); }
 
  mint pow(u128 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
 
  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }
 
  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = montgomery64(t);
    return (is);
  }
 
  mint inverse() const { return pow(mod - 2); }
 
  u64 get() const {
    u64 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }
 
  static u64 get_mod() { return mod; }
};
typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;
 
namespace fast_factorize {
  using u64 = uint64_t;
 
  template <typename mint>
  bool miller_rabin(u64 n, vector<u64> as) {
    if (mint::get_mod() != n) mint::set_mod(n);
    u64 d = n - 1;
    while (~d & 1) d >>= 1;
    mint e{1}, rev{int64_t(n - 1)};
    for (u64 a : as) {
      if (n <= a) break;
      u64 t = d;
      mint y = mint(a).pow(t);
      while (t != n - 1 && y != e && y != rev) {
	y *= y;
	t *= 2;
      }
      if (y != rev && t % 2 == 0) return false;
    }
    return true;
  }
 
  bool is_prime(u64 n) {
    if (~n & 1) return n == 2;
    if (n <= 1) return false;
    if (n < (1LL << 30))
      return miller_rabin<ArbitraryLazyMontgomeryModInt>(n, {2, 7, 61});
    else
      return miller_rabin<montgomery64>(
					n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
  }
 
  template <typename mint, typename T>
  T pollard_rho(T n) {
    if (~n & 1) return 2;
    if (is_prime(n)) return n;
    if (mint::get_mod() != n) mint::set_mod(n);
    mint R, one = 1;
    auto f = [&](mint x) { return x * x + R; };
    auto rnd_ = [&]() { return rng() % (n - 2) + 2; };
    while (1) {
      mint x, y, ys, q = one;
      R = rnd_(), y = rnd_();
      T g = 1;
      constexpr int m = 128;
      for (int r = 1; g == 1; r <<= 1) {
	x = y;
	for (int i = 0; i < r; ++i) y = f(y);
	for (int k = 0; g == 1 && k < r; k += m) {
	  ys = y;
	  for (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));
	  g = inner::gcd<T>(q.get(), n);
	}
      }
      if (g == n) do
		    g = inner::gcd<T>((x - (ys = f(ys))).get(), n);
	while (g == 1);
      if (g != n) return g;
    }
    exit(1);
  }
 
  using i64 = long long;
 
  vector<i64> inner_factorize(u64 n) {
    if (n <= 1) return {};
    u64 p;
    if (n <= (1LL << 30))
      p = pollard_rho<ArbitraryLazyMontgomeryModInt, uint32_t>(n);
    else
      p = pollard_rho<montgomery64, uint64_t>(n);
    if (p == n) return {i64(p)};
    auto l = inner_factorize(p);
    auto r = inner_factorize(n / p);
    copy(begin(r), end(r), back_inserter(l));
    return l;
  }
 
  vector<i64> factorize(u64 n) {
    auto ret = inner_factorize(n);
    sort(begin(ret), end(ret));
    return ret;
  }
 
  map<i64, i64> factor_count(u64 n) {
    map<i64, i64> mp;
    for (auto &x : factorize(n)) mp[x]++;
    return mp;
  }
 
  vector<i64> divisors(u64 n) {
    if (n == 0) return {};
    vector<pair<i64, i64>> v;
    for (auto &p : factorize(n)) {
      if (v.empty() || v.back().first != p) {
	v.emplace_back(p, 1);
      } else {
	v.back().second++;
      }
    }
    vector<i64> ret;
    auto f = [&](auto rc, int i, i64 x) -> void {
      if (i == (int)v.size()) {
	ret.push_back(x);
	return;
      }
      for (int j = v[i].second;; --j) {
	rc(rc, i + 1, x);
	if (j == 0) break;
	x *= v[i].first;
      }
    };
    f(f, 0, 1);
    sort(begin(ret), end(ret));
    return ret;
  }
 
}  // namespace fast_factorize
 
using fast_factorize::divisors;
using fast_factorize::factor_count;
using fast_factorize::factorize;
using fast_factorize::is_prime;
 
/**
 * @brief 高速素因数分解(Miller Rabin/Pollard's Rho)
 * @docs docs/prime/fast-factorize.md
 */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<multiset<int>> a(n);
  
  for (int i = 0; i < n; ++i)
    {
      int a_i; cin >> a_i;
      a[i].insert(1);
      for (auto factor : fast_factorize::factorize(a_i))
	{
	  a[i].insert(factor);
	}
    }

  long long count = 0;
  
  for (int i = 0; i < n; ++i)
    {
      count += a[i].count(2);
      count += a[i].count(3);
      a[i].erase(2);
      a[i].erase(3);
    }

  bool is_same = true;
  
  for (int i = 1; i < n; ++i)
    {
      long long product_a_i = accumulate(a[i].begin(), a[i].end(), 1, [](long long acc, long long i)
      {
	return acc * i;
      });
      
      long long product_a_i_1 = accumulate(a[i - 1].begin(), a[i - 1].end(), 1, [](long long acc, long long i)
      {
	return acc * i;
      });

      if (product_a_i != product_a_i_1) is_same = false;
    }

  if (!is_same) count = -1;

  cout << count << endl;
  
  return 0;
}
