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

void dfs(vector<vector<int>> graph, int position, int col, vector<int> color)
{
  color[position] = col;
  for (int v : graph[position])
    {
      if (color[v] == -1) dfs(v, 1 - col);
    }
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
      a--; b--;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

  vector<int> color(n, -1);
  
  dfs(graph, 0, 0, color);

  for (int i = 0; i < n; ++i)
    {
      if (color[i]) cout << i + 1 << " ";
    }
  
  return 0;
}
