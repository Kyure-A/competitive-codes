#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
/* ------------------------------ code  ------------------------------ */

// 二部グラフ判定
vector<int> color;
bool dfs(const vector<vector<int>> &G, int v, int cur = 0)
{
  color[v] = cur;
  for (auto next_v : G[v])
    {
      // 隣接頂点がすでに色確定していた場合
      if (color[next_v] != -1)
	{
	  if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
	  continue;
	}
      
      // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
      if (!dfs(G, next_v , 1 - cur)) return false;
    }
  
  return true;
}


signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<vector<int>> graph(n);

  for (int i = 0; i < n; ++i)
    {
      int a, b; cin >> a >> b;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

  color.assign(n, -1);
  
  for (int i = 0; i < n; ++i)
    {
      if (color[i] != -1) continue;
      dfs(graph, i);
    }
  
  for (int i = 0; i < n; ++i)
    {
      if (color[i] == 0)
	{
	  cout << i + 1 << " ";
	}
    }

  cout << endl;

  return 0;
}
