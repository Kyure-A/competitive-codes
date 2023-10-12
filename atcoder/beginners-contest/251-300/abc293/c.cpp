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

// O(HW)
vector<vector<int>> grid_bfs(vector<string> &str, char start, string wall)
{
  const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  const int height = str.size(), width = str[0].size();
  vector<vector<int>> distance(height, vector<int>(width, -1)); // -1 の場合は未訪問
  queue<pair<int, int>> que; // first in first out
  for (int i = 0; i < height; ++i)
    {
      for (int j = 0; j < (int)str[i].size(); ++j)
	{
	  if (str[i][j] == start)
	    {
	      que.emplace(i, j);
	      distance[i][j] = 0;
	    }
	}
    }

  while (!que.empty())
    {
      auto grid = que.front(); que.pop();
      for (int i = 0; i < 4; ++i)
	{
	  int nx = grid.second + dx[i], ny = grid.first + dy[i];
	  if (nx < 0 or ny < 0 or nx >= width or ny >= height or nx < grid.second or ny < grid.first) continue;
	  if (distance[ny][nx] != -1) continue;
	  if (wall.find(str[ny][nx]) != string::npos) continue;
	  distance[ny][nx] = distance[grid.first][grid.second] + 1;
	  que.emplace(ny, nx);
	}
    }
  return distance;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  
  vector<vector<string>> a(h, vector<string>(w));
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  cin >> a[i][j];
	}
    }

  return 0;
}
