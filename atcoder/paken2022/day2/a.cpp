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

  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  set<int> ver; // ここを vector にしていて無限に WA, いや vector でも ver に入る頂点が同じ番号のものを重複させなければ計算量は爆発しないです
  
  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      graph[a].emplace_back(b);
      ver.emplace(a);
      ver.emplace(b);
    }
  
  set<int> ans;
  
  vector<bool> seen(n + 1, false); // 最初は毎回作り直してたけど、よくよく考えたら訪問したところを再度通った場合の一番深い頂点って変わらないので
  
  for (auto x : ver) // 最初は 1 - n までのループ回してた、これが TLE に繋がってたかはあいまい
    {
      // 1-indexed
      stack<int> stk; // last in first out

      seen[x] = true; stk.emplace(x); // 初期化

      // Start
      while (!stk.empty())
	{
	  auto v = stk.top(); stk.pop(); // v に実質的に stack の一番上を移動

	  // v に隣接している頂点をすべて調べる
	  for (auto near_v : graph[v])
	    {
	      if (seen[near_v]) continue; 
	      
	      seen[near_v] = true;
	      stk.emplace(near_v); // 次に訪れるために追加する
	    }

	  if (graph[v].empty()) ans.emplace(v); // 自身から自身にしかいけない場合（めんどうなので、自分自身に隣接しており 1 個しかない場合と empty の場合って同じだし、この処理にした）
	    }
    }

  for (int i = 1; i <= n; ++i) if (!seen[i]) ans.insert(i);
  
  cout << ans.size() << endl;
  for (auto v : ans) cout << v << " ";
  cout << endl;
  
  return 0;
}
