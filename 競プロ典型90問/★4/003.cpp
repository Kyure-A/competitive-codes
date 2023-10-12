/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/modint>
// #include <boost/multiprecision/cpp_int.hpp>
/* ------------------------------  using  ------------------------------ */
using namespace std;
// using namespace atcoder;
// using namespace boost::multiprecision;
/* ------------------------------  define ------------------------------ */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<vector<int>> graph(n + 1);

  for (int i = 0; i < n; ++i)
    {
      int a, b; cin >> a >> b;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

  // 1-indexed

  vector<int> distance(n + 1, -1); // -1 の場合は未訪問
  queue<int> que; // first in first out

  distance[1] = 0; que.emplace(1); // 初期化

  // Start
  while (!que.empty())
    {
      auto v = que.front(); que.pop(); // v に実質的に queue の先頭を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (distance[near_v] != -1 and distance[near_v] > distance[v] + 1) continue; 
	  
	  distance[near_v] = distance[v] + 1;
	  que.emplace(near_v); // 次に訪れるために追加する
	}
    }

  cout << *max_element(distance.begin(), distance.end()) + 1 << endl;
  
  return 0;
}
