/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/all>
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
/* ------------------------------  const  ------------------------------ */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;
/* ------------------------------  code   ------------------------------ */

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen) {
  // 頂点 v を探索済みにする
  seen[v] = true;
  // G[v] に含まれる頂点 v2 について、
  for(auto v2 : G[v]) {
    // v2 がすでに探索済みならば、スキップする
    if(seen[v2]) {continue;}
    // v2 始点で深さ優先探索を行う (関数を再帰させる)
    dfs(v2, G, seen);
  }
  return;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < n; ++i)
    {
      int a, b; cin >> a; b = a + 1;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

  vector<bool> seen(n + 1, false);    // seen[v]：頂点 v が探索済みなら true, そうでないなら false
  int ans = 0;
  // 全ての頂点について
  for(int v = 1; v <= n; ++v) {
    // 頂点 v がすでに訪問済みであれば、スキップ
    if(seen[v]) {continue;}
    // そうでなければ、頂点 v を含む連結成分は未探索
    // 深さ優先探索で新たに訪問し、答えを 1 増やす
    dfs(v, graph, seen);
    ans = max(ans, v);

    for (int j = ans; j >= v; ++j)
      {
	cout << j << " ";
      }

    v = ans;
  }
  
  return 0;
}
