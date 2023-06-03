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
    vector<int> indegrees;
    vector<int> result;

    TopologicalSort (int vertex_size): V(vertex_size), graph(V), indegrees(V, 0) {}
  
    void add_edge(int from, int to) // 0 <= from, to < V
    {
      graph[from].emplace_back(to);
      indegrees[to]++;
    }
  
    bool solve_ascending()
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

    bool solve_descending()
    {
      priority_queue<int, vector<int>> que;

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
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  
  kyre::TopologicalSort graph_asc(n), graph_des(n);
  for (int i = 0; i < m; ++i)
    {
      int x, y; cin >> x >> y;
      x--; y--;
      graph_asc.add_edge(x, y);
      graph_des.add_edge(x, y);
    }

  graph_asc.solve_ascending();
  graph_des.solve_descending();

  if (graph_asc.result == graph_des.result)
    {
      cout << "Yes" << endl;
      
      vector<int> a(n);
      int count = 1;
      for (auto v : graph_asc.result)
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
