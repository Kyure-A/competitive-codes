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
  
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> graph(n);

  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      a--; b--;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

  vector<int> p(k), h(k);

  for (int i = 0; i < k; ++i)
    {
      cin >> p[i] >> h[i];
      p[i]--; h[i]--;
    }

  vector<int> distance(n, -1); 
  queue<int> que;

  for (auto v : p)
    {
      distance[v] = 0;
      que.emplace(v);
    }
  
  while (!que.empty())
    {
      auto v = que.front(); que.pop();
      
      for (auto near_v : graph[v])
	{
	  if (distance[near_v] != -1) continue; 
	  
	  distance[near_v] = distance[v] + 1;
	  que.emplace(near_v);
	}
    }

  for (int i = 0; i < n; ++i)
    {
      cout << i << "の距離: " << distance[i] << endl;
    }
  
  // vector<int> guarded;

  // sort(h.begin(), h.end());
  
  // for (int i = 0; i < n; i++)
  //   {
  //     if (distance[i] == -1) continue;

  //     if (lower_bound(h.begin(), h.end(), distance[i]) != h.end())
  // 	{
  // 	  guarded.emplace_back(i);
  // 	}
  //   }

  // sort(guarded.begin(), guarded.end());

  // cout << guarded.size() << endl;

  // for (auto v : guarded)
  //   {
  //     cout << v + 1 << " ";
  //   }

  // cout << endl;

  return 0;
}
