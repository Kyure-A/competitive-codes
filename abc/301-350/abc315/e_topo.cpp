#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/modint>
// using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

namespace kyre
{
  using namespace std;
  
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
  
    bool sort_ascending() // 複数のトポロジカルソートがある場合、辞書順最小のものを得る
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

    bool sort_descending() // 複数のトポロジカルソートがある場合、辞書順最大のものを得る
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

    bool solve() // トポロジカルソートをする
    {
      sort_ascending();
      sort_descending();
      return sort_descending() or sort_descending();
    }
    
    bool is_DAG() // solve() と同じだが、わかりやすいので
    {
      return solve();
    }

    bool is_unique () // ABC 291 E のように一意にソートできるかという問題に有効
    {
      solve();
      return result_ascending == result_descending;
    }

    vector<int> result (string order = "ascending")
    {
      solve();
      if (order == "ascending") return result_ascending;
      else return result_descending;
    }
    
  };
}


signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  kyre::TopologicalSort tree(n);

  vector<bool> is_dependency(n, false);
  is_dependency[0] = true;
  
  for (int i = 0; i < n; ++i)
    {
      int c; cin >> c;
      
      for (int j = 0; j < c and is_dependency[i]; ++j)
	{
	  int p; cin >> p; p--;
	  is_dependency[p] = true;
	  tree.add_edge(i, p);
	}
    }

  tree.solve();

  for (auto x : tree.result())
    {
      cout << x << endl;
    }

  return 0;
}

