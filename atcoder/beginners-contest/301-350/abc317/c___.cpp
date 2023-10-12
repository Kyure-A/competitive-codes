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

// editorial AC
signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<vector<int>> edge(n, vector<int>(n, -1));
  
  for (int i = 0; i < m; ++i)
    {
      int a, b, c; cin >> a >> b >> c;
      a--; b--;
      edge[a][b] = edge[b][a] = c;
    }

  vector<bool> seen(n, false);
  int answer = 0;
  
  auto dfs = [&](auto&& self, int v, int sum) -> void
  {
    seen[v] = true;
    answer = max(answer, sum);

    for (int i = 0; i < n; ++i)
      {
	if (!seen[i] and edge[v][i] != -1) self(self, i, sum + edge[v][i]);
      }
    
    seen[v] = false;
  };

  for (int i = 0; i < n; ++i)
    {
      dfs(dfs, i, 0);
    }

  cout << answer << endl;
  
  return 0;
}
