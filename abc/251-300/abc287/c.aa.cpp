/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
typedef long long i64;
typedef long long int64;
typedef long long ll;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;

using Graph = vector<vector<int>>;
vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true; // v を訪問済にする

  // v から行ける各頂点 next_v について
  for (auto next_v : G[v]) { 
    if (seen[next_v]) continue; // next_v が探索済だったらスルー
    dfs(G, next_v); // 再帰的に探索
  }
}

signed main ()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n + 1);

  for (int i = 0; i < m; ++i)
    {
      int u, v; cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

  
  vector<bool> seen(n + 1, false); 
  queue<int> que;
  
  seen[1] = true;
  que.push(1);

  while (!que.empty())
    {
      int v = que.front(); 
      que.pop();

      for (int nv : graph[v])
      {
	if (!seen[nv])
	{
	  seen[nv] = true;
	  que.push(nv);
	}
      }
    }

  int deg1 = 0;
  int deg2 = 0;
  bool flag = true;
  
  for (int i = 1; i <= n; ++i)
    {
      if (graph[i].size() == 1) deg1++;
      else if (graph[i].size() == 2) deg2++;

      if (!seen[i]) flag = false;
    }
  
  if (deg1 == 2 and deg2 == n - 2 and flag) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
