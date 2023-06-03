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


vector<int> bfs(int n, const vector<vector<int>> &g, const vector<pair<int, int>> &sources)
{
  vector<int> dist(n, 1e9);
  vector<vector<int>> bucket(n + 1);
  
  for (auto [v, d] : sources)
    {
      assert(-n <= d && d <= 0);
      dist[v] = d;
      bucket[n + d].push_back(v);
    }
  
  queue<int> que_init, que_bfs;
  
  rep(i, n + 1) for (int v : bucket[i]) que_init.push(v);
  
  vector<char> visited(n);
  
  while (!que_init.empty() || !que_bfs.empty())
    {
      int u;
      
      if (!que_init.empty() && (que_bfs.empty() || dist[que_init.front()] < dist[que_bfs.front()]))
	{
	  u = que_init.front();
	  que_init.pop();
	}
      
      else
	{
	  u = que_bfs.front();
	  que_bfs.pop();
	}
      
      if (visited[u]) continue;
      
      visited[u] = true;
      
      for (int v : g[u])
	{
	  if (dist[u] + 1 < dist[v])
	    {
	      dist[v] = dist[u] + 1;
	      que_bfs.push(v);
	    }
	}
    }
  
  return dist;
}

signed main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  
  vector<vector<int>> graph(n);
  
  rep(_, m)
    {
      int u, v;
      cin >> u >> v;
      u--, v--;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
  
  int k; cin >> k;
  
  vector<pair<int, int>> pd(k);
  
  for (auto &[p, d] : pd)
    {
      cin >> p >> d;
      p--;
      d *= -1;
    }
  
  vector<int> t = bfs(n, graph, pd);
  vector<pair<int, int>> blacks;
  
  rep(i, n) if (t[i] >= 0) blacks.emplace_back(i, 0);
  
  vector<int> dist = bfs(n, graph, blacks);
  
  for (auto [p, d] : pd)
    {
      if (dist[p] != -d)
	{
	  cout << "No" << endl;
	  return 0;
	}
    }
  cout << "Yes" << endl;
  
  string ans;
  
  rep(i, n) ans += t[i] < 0 ? '0' : '1';
  
  cout << ans << endl;
}
