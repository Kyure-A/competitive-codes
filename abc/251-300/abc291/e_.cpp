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

namespace kyre
{
  class TopologicalSort
  {  
  public:
    int V;
    vector<vector<int>> graph;
    vector<int> indegrees_ascending, indegrees_descending;
    vector<int> result_ascending, result_descending;
    
    TopologicalSort (int vertex_size):
      V(vertex_size), graph(V), indegrees_ascending(V, 0), indegrees_descending(V, 0) {}
  
    void add_edge(int from, int to) // 0 <= from, to < V
    {
      graph[from].emplace_back(to);
      indegrees_ascending[to]++;
      indegrees_descending[to]++;
    }
  
    bool solve_ascending() // 複数のトポロジカルソートがある場合、辞書順最小のものを得る
    {
      if (result_ascending.empty())
	{
	  priority_queue<int, vector<int>, greater<int>> que;

	  for (int i = 0; i < V; ++i)
	    {
	      if (indegrees_ascending[i] == 0)
		{
		  que.emplace(i);
		}
	    }
    
	  while (!que.empty())
	    {
	      const int from = que.top(); que.pop();

	      result_ascending.emplace_back(from);

	      for (const auto& to : graph[from])
		{
		  if (--indegrees_ascending[to] == 0)
		    {
		      que.emplace(to);
		    }
		}
	    }
	}

      return (*max_element(indegrees_ascending.begin(), indegrees_ascending.end()) == 0);
    }

    bool solve_descending() // 複数のトポロジカルソートがある場合、辞書順最大のものを得る
    {
      if (result_descending.empty())
	{
	  priority_queue<int, vector<int>> que;

	  for (int i = 0; i < V; ++i)
	    {
	      if (indegrees_descending[i] == 0)
		{
		  que.emplace(i);
		}
	    }
    
	  while (!que.empty())
	    {
	      const int from = que.top(); que.pop();

	      result_descending.emplace_back(from);

	      for (const auto& to : graph[from])
		{
		  if (--indegrees_descending[to] == 0)
		    {
		      que.emplace(to);
		    }
		}
	    }
	}

      return (*max_element(indegrees_descending.begin(), indegrees_descending.end()) == 0);
    }

    bool solve()
    {
      solve_ascending();
      solve_descending();
      return solve_descending() or solve_descending();
    }
    
    bool is_DAG()
    {
      return solve();
    }

    bool is_unique () // ABC 291 E のように一意にソートできるかという問題に有効
    {
      return result_ascending == result_descending;
    }

    vector<int> result (string order = "ascending")
    {
      if (order == "ascending") return result_ascending;
      else return result_descending;
    }
  };
}

signed main () // test
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  
  kyre::TopologicalSort graph(n);
  for (int i = 0; i < m; ++i)
    {
      int x, y; cin >> x >> y;
      x--; y--;
      graph.add_edge(x, y);
    }

  graph.solve();
  graph.solve();
  graph.solve();
  graph.solve();
  graph.solve();
  graph.solve();
  graph.solve();
  graph.solve();
  graph.solve();
  graph.solve();
  
  if (graph.is_unique())
    {
      cout << "Yes" << endl;
      
      vector<int> a(n);
      int count = 1;
      for (auto v : graph.result())
	{
	  a[v] = count;
	  count++;
	}

      for (int i = 0; i < n; ++i)
	{
	  cout << a[i] << " ";
	}
      
      cout << endl;
    }
  
  else cout << "No" << endl; 

  return 0;
}
