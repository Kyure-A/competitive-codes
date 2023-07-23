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

// O(HW)
vector<vector<int>> grid_dfs(vector<string> &str, string wall)
{
  const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  const int height = str.size(), width = str[0].size();
  vector<vector<int>> distance(height, vector<int>(width, -1)); // -1 の場合は未訪問
  stack<pair<int, int>> stk; // first in first out

  stk.emplace(1, 1);
  distance[1][1] = 0;

  int came_dir = 0;
  
  while (!stk.empty())
    {
      auto grid = stk.top(); stk.pop();
      for (int i = 0; i < 4; ++i)
	{
	  int nx = grid.second + dx[i], ny = grid.first + dy[i];
	  if (nx < 0 or ny < 0 or nx >= width or ny >= height) continue;
	  if (distance[ny][nx] != -1) continue;
	  if (wall.find(str[ny][nx]) != string::npos) continue;
	  distance[ny][nx] = distance[grid.first][grid.second] + 1;
	  stk.emplace(ny, nx);
	}
    }
  return distance;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<string> s(n); rep(i, n) cin >> s[i];

  vector<vector<int>> ans = grid_bfs(s, "#");

  int count = 0;

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
	{
	  if (ans[i][j] != -1) count++;
	}
    }

  cout << count << endl;
  
  return 0;
}
