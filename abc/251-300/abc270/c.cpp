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

// 参考: https://atcoder.jp/contests/abc270/submissions/39346453
// UnionFind みがあっていいね

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, x, y; cin >> n >> x >> y;
  vector<vector<int>> graph(n + 1);
  
  for (int i = 0; i < n; ++i)
    {
      int u, v; cin >> u >> v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

  // 1-indexed
  
  vector<int> parent(n + 1, -1); // -1 の場合は未訪問
  stack<int> stk; // last in first out

  parent[y] = 0; stk.emplace(y); // 初期化
  
  // Start
  while (!stk.empty())
    {
      auto v = stk.top(); stk.pop();// v に実質的に stack の一番上を移動
      
      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (parent[v] == near_v) continue;
	  parent[near_v] = v;
	  stk.emplace(near_v);
	}
    }

  for (int i = x; i != 0; i = parent[i])
    {
      cout << i << " ";
    }

  cout << "\n";

  return 0;
}
