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

int h, w;
vector<string> grid;
vector<vector<bool>> visited;

bool dfs(int i, int j, int t) {
  
  char predict = "snuke"[t % 5];
  
  if (i == h - 1 and j == w - 1)
    {
      if (predict == grid[i][j]) return true;
      else return false;
    }
  
  visited[i][j] = true;

  int di[4] = {-1, 1, 0, 0};
  int dj[4] = {0, 0, -1, 1};

  for (int k = 0; k < 4; k++) {
    int ni = i + di[k];
    int nj = j + dj[k];

    if (grid[ni][nj] != predict) continue;
    
    if (0 <= ni and ni < h and 0 <= nj and nj < w and !visited[ni][nj])
      {
	if (dfs(ni, nj, t + 1)) return true;
      }
  }

  visited[i][j] = false;  // バックトラック

  return false;
}

signed main() {
  
  cin >> h >> w;

  grid.resize(h);
  for (int i = 0; i < h; i++)
    {
      cin >> grid[i];
    }

  visited.resize(h, vector<bool>(w, false));

  if (dfs(0, 0, 0)) cout << "Yes" << endl;
  
  else cout << "No" << endl;
   

  return 0;
}
