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
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

class TopologicalSort
{  
public:
  int V;
  vector<vector<int>> graph;
  vector<int> indegrees;
  vector<int> result;

  TopologicalSort (int vertex_size): V(vertex_size), graph(V), indegrees(V, 0) {}
  
  void add_edge(int from, int to) // 0 <= from, to < V
  {
    graph[from].emplace_back(to);
    indegrees[to]++;
  }
  
  bool dag()
  {
    priority_queue<int, vector<int>, greater<int>> que;

    for (int i = 0; i < V; ++i)
      {
	if (indegrees[i] == 0)
	  {
	    que.push(i);
	  }
      }
    
    while (!que.empty())
      {
	const int from = que.top(); que.pop();

	result.push_back(from);

	for (const auto& to : graph[from])
	  {
	    if (--indegrees[to] == 0)
	      {
		que.push(to);
	      }
	  }
      }

    return (*max_element(indegrees.begin(), indegrees.end()) == 0);
  }

  vector<int> sorted()
  {
    return result;
  }
  
};

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  TopologicalSort graph(n);

  for (int i = 0; i < n; ++i)
    {
      int x, y; cin >> x >> y;
      // 0 indexed
      x--; y--;
      graph.add_edge(x, y);
    }

  if (!graph.dag()) cout << -1 << endl;
  else
    {
      for (auto v : graph.sorted()) cout << v << " ";
    }
  
  return 0;
}
