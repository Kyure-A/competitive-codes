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

map<pair<int, int>, bool> seen;

void dfs (map<pair<int, int>, vector<pair<int, int>>> &G, pair<int, int> start)
{
  seen[start] = true;
  for (auto next : G[start])
    {
      if (!seen[next])
	{
	  dfs(G, next);
	}
    }
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w)); rep(i, h) rep(j, w) cin >> a[i][j];
  map<pair<int, int>, vector<pair<int, int>>> graph;

  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  if (0 <= i + 1 and i + 1 < h) graph[{i, j}].push_back({i + 1, j});
	  if (0 <= j + 1 and j + 1 < w) graph[{i, j}].push_back({i, j + 1});
	}
    }
  
  return 0;
}
