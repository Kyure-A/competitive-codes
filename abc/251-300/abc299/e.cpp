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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  
  for (int i = 0; i < m; ++i)
    {
      int u, v; cin >> u >> v;
      u--; v--;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

  vector<int> distance(n, -1); // -1 の場合は未訪問
  queue<int> que; // first in first out

  int k; cin >> k;
  vector<int> p(k), d(k);
  
  for (int i = 0; i < k; ++i)
    {
      cin >> p[i] >> d[i];
      p[i]--;
      distance[p[i]] = 0;
      que.emplace(p[i]);
    }

  // Start
  while (!que.empty())
    {
      auto v = que.front(); que.pop(); // v に実質的に queue の先頭を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (distance[near_v] != -1) continue; 
	  
	  distance[near_v] = distance[v] + 1;
	  que.emplace(near_v); // 次に訪れるために追加する
	}
    }

  
  /*
    for (int i = 0; i < n; ++i)
    {
      cout << "distance[" << i << "]: " << distance[i] <<endl; 
    }
  */
    
  return 0;
}
