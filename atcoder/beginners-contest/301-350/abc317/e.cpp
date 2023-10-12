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
	  if (nx < 0 or ny < 0 or nx >= width or ny >= height) continue;
	  if (distance[ny][nx] != -1) continue;
	  if (wall.find(str[ny][nx]) != string::npos) continue;
	  distance[ny][nx] = distance[grid.first][grid.second] + 1;
	  que.emplace(ny, nx);
	}
    }
  return distance;
}

bool is_trainer(char c)
{
  return c == '>' or c == '<' or c == 'v' or c == '^';
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int h, w; cin >> h >> w;
  vector<string> a(h); rep(i, h) cin >> a[i];
  pair<int, int> goal = {-1, -1};
  // トレーナーの処理
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  char grid = a[i][j];
	  if (grid == 'v')
	    {
	      for (int k = i + 1; k < h; ++k)
		{
		  if (a[k][j] == '.' or a[k][j] == '!') a[k][j] = '!';
		  else break;
		}
	    }

	  if (grid == '^')
	    {
	      for (int k = i - 1; k >= 0; --k)
		{
		  if (a[k][j] == '.' or a[k][j] == '!') a[k][j] = '!';
		  else break;
		}
	    }

	  if (grid == '<')
	    {
	      for (int k = j - 1; k >= 0; --k)
		{
		  if (a[i][k] == '.' or a[i][k] == '!') a[i][k] = '!';
		  else break;
		}
	    }

	  if (grid == '>')
	    {
	      for (int k = j + 1; k < w; ++k)
		{
		  if (a[i][k] == '.' or a[i][k] == '!') a[i][k] = '!';
		  else break;
		}
	    }

	  if (grid == 'G') goal = {i, j};
	}
    }

  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  if (a[i][j] == '!' or
	      a[i][j] == '>' or
	      a[i][j] == '<' or
	      a[i][j] == '^' or
	      a[i][j] == 'v') a[i][j] = '#';
	}
    }

  for (auto x : a) cout << x << endl;
  
  vector<vector<int>> distance = grid_bfs(a, 'S', "#");

  cout << distance[goal.first][goal.second] << endl;
  
  return 0;
}
