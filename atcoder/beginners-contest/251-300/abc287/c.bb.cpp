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
  
  int deg1 = 0;
  int deg2 = 0;
  
  for (int i = 1; i <= n; ++i)
    {
      sort(all(graph[i]));
      graph[i].erase(unique(all(graph[i])), graph[i].end());
      if (graph[i].size() == 1) deg1++;
      else if (graph[i].size() == 2) deg2++;
    }
  
  if (deg1 == 2 and deg2 == n - 2) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
