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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);

  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      a--; b--;
      graph[a].push_back(b);
    }

  vector<vector<int>> kateru(n);

  int detected_loop = false;
  
  for (int i = 0; i < n; ++i)
    {
      // 1-indexed

      vector<int> distance(n + 1, -1); // -1 の場合は未訪問
      stack<int> que; // first in first out

      distance[i] = 0; que.emplace(i); // 初期化

      // Start
      while (!que.empty())
	{
	  auto v = que.top(); que.pop(); // v に実質的に queue の先頭を移動

	  // v に隣接している頂点をすべて調べる
	  for (auto near_v : graph[v])
	    {
	      if (distance[near_v] != -1)
		{
		  detected_loop = true;
		  continue;
		}
	      
	      distance[near_v] = distance[v] + 1;
	      que.emplace(near_v); // 次に訪れるために追加する
	      kateru[i].push_back(near_v);
	    }
	}
      
    }

  vector<pair<int, int>> pr;
  
  for (int i = 0; i < n; i++)
    {
      pr.push_back({kateru[i].size(), i + 1});
    }

  sort(all(pr), greater<pair<int, int>>());

  if (detected_loop) cout << -1 << endl;
  else {

    for (int i = 1; i < n; ++i)
      {
	if (pr[i].first == pr[i - 1].first)
	  {
	    cout << -1 << endl;
	    return 0;
	  }
      }

    cout << pr[0].second << endl;
  }
  
  return 0;
}
