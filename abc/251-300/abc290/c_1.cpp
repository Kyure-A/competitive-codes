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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

template <bool Strict, class Type>
std::vector<size_t> LIS(const std::vector<Type>& v)
{
  std::vector<Type> dp;

  auto it = dp.begin();

  // 最長増加部分列の長さの途中経過を記録する配列
  std::vector<size_t> counts;

  for (const auto& elem : v)
    {
      if constexpr (Strict)
	{
	  it = std::lower_bound(dp.begin(), dp.end(), elem);
	}
      else
	{
	  it = std::upper_bound(dp.begin(), dp.end(), elem);
	}

      if (it == dp.end())
	{
	  dp.push_back(elem);
	}
      else
	{
	  *it = elem;
	}

      counts.push_back(dp.size());
    }

  return counts;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k; cin >> n >> k;
  vector<int> a(n); rep(i, n) cin >> a[i];
  int size = LIS<true>(a)[k];
  cout << size << endl;

  return 0;
}
