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

  int h, w; cin >> h >> w;
  vector<vector<char>> g(h, vector<char>(w)); rep(i, h) rep(j, w) cin >> g[i][j];
  map<pair<int, int>, int> seen;
  
  pair<int, int> now = make_pair(0, 0);
  seen[now] = 1;
  
  while (true)
    {
      if (g[now.first][now.second] == 'U' and now.first != 0)
	{
	  now.first--;
	  seen[now]++;
	}

      else if (g[now.first][now.second] == 'D' and now.first != h - 1)
	{
	  now.first++;
	  seen[now]++;
	}
      
      else if (g[now.first][now.second] == 'L' and now.second != 0)
	{
	  now.second--;
	  seen[now]++;
	}

      else if (g[now.first][now.second] == 'R' and now.second != w - 1)
	{
	  now.second++;
	  seen[now]++;
	}

      else
	{
	  cout << now.first + 1 << " " << now.second + 1 << endl;
	  return 0;
	}
      
      // move inf
      
      if (seen[now] > 1)
	{
	  cout << "-1" << endl;
	  return 0;
	}
    }
  
  return 0;
}
