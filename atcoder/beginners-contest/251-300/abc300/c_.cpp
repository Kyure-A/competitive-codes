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

class UnionFind
{
public:
  map<pair<int, int>, pair<int, int>> parent;
  map<pair<int, int>, int> set_size;

  // constructor
  UnionFind (int h, int w): parent(), set_size()
  {
    for (int i = 0; i < h; ++i)
      {
	for (int j = 0; j < w; ++j)
	  {
	    parent[{i, j}] = {i, j};
	    set_size[{i, j}] = 1;
	  }
      }
  }

  pair<int, int> root (pair<int, int> x) // find (path halving)
  {
    while (parent[x] != x)
      {
	parent[x] = parent[parent[x]];
	x = parent[x];
      }

    return x;
  }

  bool merge (pair<int, int> x, pair<int, int> y) // union by size
  {
    pair<int, int> rx = root(x);
    pair<int, int> ry = root(y);

    if (rx == ry) return false;
    else if (set_size[rx] < set_size[ry]) swap(rx, ry); // root(y) のほうがデカいときも merge できるように逆にする
    
    // Operations
    parent[ry] = rx;
    set_size[rx] += set_size[ry];
    return true;
  }

  bool same (pair<int, int> x, pair<int, int> y)
  {
    return root(x) == root(y);
  }

  int size(pair<int, int> x)
  {
    return set_size[root(x)];
  }

};

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  vector<vector<char>> c(h, vector<char>(w)); rep(i, h) rep(j, w) cin >> c[i][j];
  UnionFind tree(h, w);
  
  // init
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  if (c[i][j] == '#' and i + 1 < h and j + 1 < w)
	    {
	      if (c[i + 1][j + 1] == '#') tree.merge({i, j}, {i + 1, j + 1});
	    }

	  if (c[i][j] == '#' and i + 1 < h and j - 1 >= 0)
	    {
	      if (c[i + 1][j - 1] == '#') tree.merge({i, j}, {i + 1, j - 1});
	    }

	      if (c[i][j] == '#' and i - 1 >= 0 and j + 1 < h)
	    {
	      if (c[i - 1][j + 1] == '#') tree.merge({i, j}, {i - 1, j + 1});
	    }

	      if (c[i][j] == '#' and i - 1 >= 0 and j - 1 >= 0)
	    {
	      if (c[i - 1][j - 1] == '#') tree.merge({i, j}, {i - 1, j - 1});
	    }
	}
    }

  // solve
  set<pair<int, int>> cross;
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  bool is_same = false;
	  
	  for (auto x : cross)
	    {
	      if (tree.same({i, j}, x))
		{
		  is_same = true;
		  break;
		}
	    }

	  // shama さんありがとう (https://twitter.com/c2hhbWFkYXlv_cp/status/1654012764179005440)
	  if (is_same or tree.size({i, j}) == 1) continue; // "." の集合を除く
	  
	  cross.insert({i, j});
	}
    }
  
  int n = min(h, w);
  vector<int> answer(n + 1, 0);

  for (auto x : cross)
    {
      int size = tree.size(x) / 4; // floor
      answer[size]++;
    }

  for (int i = 1; i <= n; ++i)
    {
      cout << answer[i] << " ";
    }

  cout << endl;

  return 0;
}
