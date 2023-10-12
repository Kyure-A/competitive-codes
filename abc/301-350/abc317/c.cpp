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
const long long INF = 1e17;

void warshall_floyd(vector<vector<long long>> &dist) {
  int V = dist.size();
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<vector<long long>> graph(n, vector<long long>(n, INF)); 

  for (int i = 0; i < n; ++i)
    {
      graph[i][i] = 0;
    }
  
  for (int i = 0; i < m; ++i)
    {
      long long a, b, c; cin >> a >> b >> c;
      a--; b--;
      graph[a][b] = -c;
      graph[b][a] = -c;
    }

  warshall_floyd(graph);

  long long result = 0;
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  result = min(result, graph[i][j]);
	}
    }

  cout << result << endl;
  
  return 0;
}
