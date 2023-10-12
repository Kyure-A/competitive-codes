#include <bits/stdc++.h>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

bool comp (vector<int> x, vector<int> y)
{
  return x.size() > y.size();
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;

  vector<vector<int>> gr(n + 1);
  
  scc_graph graph(n + 1);
  
  for (int i = 1; i <= n; ++i)
    {
      int a; cin >> a;
      graph.add_edge(i, a);
      gr[i].push_back(a);
    }

  vector<vector<int>> graph_scc = graph.scc();

  sort(all(graph_scc), comp);

  set<int> ans(graph_scc[0].begin(), graph_scc[0].end());
  
  int start = graph_scc[0][0];
  cout << graph_scc[0].size() << endl << start << " ";

  // 1-indexed

  vector<bool> seen(n + 1, false); // -1 の場合は未訪問
  stack<int> stk; // last in first out

  seen[start] = true; stk.emplace(start); // 初期化

  // Start
  while (!stk.empty())
    {
      auto v = stk.top(); stk.pop(); // v に実質的に stack の一番上を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : gr[v])
	{
	  if (ans.count(near_v) == 0) continue;
	  if (seen[near_v]) return 0;
	  
	  seen[near_v] = true;
	  cout << near_v << " ";
	  stk.emplace(near_v); // 次に訪れるために追加する
	}
    }
  
  return 0;
}
