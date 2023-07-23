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
constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n_1, n_2, m; cin >> n_1 >> n_2 >> m;
  vector<vector<int>> graph(n_1 + n_2 + 1);
  
  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

  // bfs

  vector<vector<int>> distance(2, vector<int>(n_1 + n_2 + 1, -1));
  queue<int> que1; // first in first out

  distance[0][1] = distance[1][n_1 + n_2] = 0;
  que1.emplace(1); // 初期化

  // V(1) -> 
  while (!que1.empty())
    {
      auto v = que1.front(); que1.pop(); // v に実質的に queue の先頭を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (distance[0][near_v] != -1) continue; 
	  
	  distance[0][near_v] = distance[0][v] + 1;
	  que1.emplace(near_v); // 次に訪れるために追加する
	}
    }

  queue<int> que2;
  
  que2.emplace(n_1 + n_2); // 初期化

  // V(N_1 + N_2) ->
  while (!que2.empty())
    {
      auto v = que2.front(); que2.pop(); // v に実質的に queue の先頭を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (distance[1][near_v] != -1) continue; 
	  
	  distance[1][near_v] = distance[1][v] + 1;
	  que2.emplace(near_v); // 次に訪れるために追加する
	}
    }

  int max_dist[2] = {0};

  for (auto x : distance[0]) max_dist[0] = max(x, max_dist[0]);
  for (auto x : distance[1]) max_dist[1] = max(x, max_dist[1]);

  cout << max_dist[0] + max_dist[1] + 1 << endl;
  
  return 0;
}
