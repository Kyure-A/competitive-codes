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

// editorial

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n); rep(i, n) cin >> a[i];
  
  atcoder::scc_graph graph(n);

  int answer = 0;
  
  for (int i = 0; i < n; ++i)
    {
      graph.add_edge(i, a[i] - 1);
      
      if (i == a[i] - 1) answer++;
      // i ならば i 回目のゲームは勝利であるため、i -> i の自己ループができていれば
      // 青木くんの K_i 回の操作に問わず高橋くんが S_i = i とすれば勝てる
    }

  for (auto scc : graph.scc())
    {
      if (scc.size() > 1) answer += scc.size();
      // i にたどり着きたいとき i の含まれる強連結成分の頂点数が 2 個以上であれば、
      // その強連結成分内の S_i を適切に選んでそれらを行ったり来たりすれば K_i に関係なく
      // i にたどり着けるので、(その条件に合致する i の個数) = scc.size()
    }

  cout << answer << endl;

  return 0;
}
