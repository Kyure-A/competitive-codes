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

// dijkstra
constexpr long long INF = (1LL << 60);

// 辺の情報
struct Edge
{
  // 行先
  int to;

  // コスト
  int cost;
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph& graph, std::vector<long long>& distances, int startIndex)
{
  // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
  // デフォルトの priority_queue は降順に取り出すため std::greater を使う
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
  q.emplace((distances[startIndex] = 0), startIndex);

  while (!q.empty())
    {
      const long long distance = q.top().first;
      const int from = q.top().second;
      q.pop();

      // 最短距離でなければ処理しない
      if (distances[from] < distance)
	{
	  continue;
	}

      // 現在の頂点からの各辺について
      for (const auto& edge : graph[from])
	{
	  // to までの新しい距離
	  const long long d = (distances[from] + edge.cost);

	  // d が現在の記録より小さければ更新
	  if (d < distances[edge.to])
	    {
	      q.emplace((distances[edge.to] = d), edge.to);
	    }
	}
    }
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<vector<Edge>> graph(n + 1);

  for (int i = 0; i < m; ++i)
    {
      int a, b, c; cin >> a >> b >> c;
      graph[a].push_back({b, c});
    }

  vector<long long> distance(n + 1, INF);

  Dijkstra(graph, distance, 1);

  for (int i = 1; i <= n; ++i)
    {
      cout << distance[i] << endl;
    }
  
  return 0;
}
