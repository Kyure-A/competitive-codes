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

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string &S) {
  int n = (int)S.size();
  vector<vector<int> > res(n+1, vector<int>(10, n));
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < 10; ++j) res[i][j] = res[i+1][j];
    res[i][S[i]-'0'] = i;
  }
  return res;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s; cin >> s;
  int n = s.size();
  
  vector<vector<int>> next = calcNext(s);
  // initialize dp table
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  
  
  return 0;
}
