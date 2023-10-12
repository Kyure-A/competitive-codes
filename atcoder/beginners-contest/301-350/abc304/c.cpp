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

long double euclidian_distance(pair<int, int> a, pair<int, int> b)
{
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; long double d; cin >> n >> d;
  vector<pair<int, int>> people(n); rep(i, n) cin >> people[i].first >> people[i].second;
  vector<bool> is_infected(n);
  is_infected[0] = true;
  vector<vector<int>> nexttopeople(n);
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (i == j) continue;
	  
	  if (euclidian_distance(people[i], people[j]) <= d)
	    {
	      nexttopeople[i].push_back(j);
	      nexttopeople[j].push_back(i);
	    }
	}
    }

  // 1-indexed

  stack<int> stk; // last in first out
  stk.emplace(0);
  vector<bool> seen(n, false);
  seen[0] = true;
  
  // Start
  while (!stk.empty())
    {
      auto v = stk.top(); stk.pop(); // v に実質的に stack の一番上を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : nexttopeople[v])
	{
	  if (seen[near_v]) continue; 
	  is_infected[near_v] = true;
	  seen[near_v] = true;
	  stk.emplace(near_v); // 次に訪れるために追加する
	}
    }
  
  for (int i = 0; i < n; ++i)
    {
      if (is_infected[i]) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

  return 0;
}
