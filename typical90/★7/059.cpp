/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
#include <atcoder/scc>
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
  
  int n, m, q; cin >> n >> m >> q;
  
  scc_graph graph(n + 1);
  for (int i = 0; i < n; ++i)
    {
      int x, y; cin >> x >> y;
      graph.add_edge(x, y);
    }

  vector<vector<int>> scc = graph.scc();
  
  while (q--)
    {
      int a, b; cin >> a >> b;

      int a_index, b_index;
      
      for (int i = 0; i < (int)scc.size(); ++i)
	{
	  bool a_exist = binary_search(scc[i].begin(), scc[i].end(), a);
	  bool b_exist = binary_search(scc[i].begin(), scc[i].end(), b);

	  if (a_exist) a_index = i;
	  if (b_exist) b_index = i;
	}

      if (a_index <= b_index) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  
  return 0;
}
