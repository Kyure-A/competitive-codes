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
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
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
  vector<vector<int>> graph(2 * n + 2);

  for (int i = 1; i <= n; ++i)
    {
      int a; cin >> a;
      int a_new[2] = {2 * i, 2 * i + 1};
      graph[a].emplace_back(a_new[0]);
      graph[a].emplace_back(a_new[1]);
      graph[a_new[0]].emplace_back(a);
      graph[a_new[1]].emplace_back(a);
    }

  // 1-indexed
  vector<int> generation(2 * n + 2, -1); // -1 の場合は未訪問
  queue<int> que; // first in first out

  generation[1] = 0; que.emplace(1); // 初期化

  // Start
  while (!que.empty())
    {
      auto v = que.front(); que.pop(); // v に実質的に queue の先頭を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (generation[near_v] != -1) continue; 
	  
	  generation[near_v] = generation[v] + 1;
	  que.emplace(near_v); // 次に訪れるために追加する
	}
    }

  for (int i = 1; i <= 2 * n + 2; ++i)
    {
      cout << generation[i] << "\n";
    }

  return 0;
}
