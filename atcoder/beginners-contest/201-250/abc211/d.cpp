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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  
  for (int i = 1; i <= m; ++i)
    {
      int a, b; cin >> a >> b;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

  vector<int> distance(n + 1, -1); // -1 の場合は未訪問
  queue<int> que; // first in first out

  distance[1] = 0; que.push(1); // 初期化
  vector<int> count(n + 1, 0);
  count[1] = 1;
  
  // Start
  while (!que.empty())
    {
      auto v = que.front(); que.pop(); // v に実質的に queue の先頭を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (distance[near_v] == -1)
	    {
	      distance[near_v] = distance[v] + 1;
	      que.push(near_v); // 次に訪れるために追加する
	      count[near_v] = count[v];
	    }
	  else if (distance[near_v] == distance[v] + 1)
	    {
	      count[near_v] += count[v];
	      count[near_v] %= MOD;
	    }
	}
    }

  cout << count[n] << "\n";
  
  return 0;
}
