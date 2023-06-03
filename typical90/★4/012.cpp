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
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

class PairedUnionFind
{
public:
  map<pair<int, int>, pair<int, int>> parent;
  map<pair<int, int>, int> set_size;
 
  // constructor
  PairedUnionFind (int h, int w): parent(), set_size()
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
    
    // Operations
    else if (set_size[rx] < set_size[ry])
      {
	parent[rx] = ry;
	set_size[ry] += set_size[rx];
      }
    else
      {
	parent[ry] = rx;
	set_size[rx] += set_size[ry];
      }
    
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
  int q; cin >> q;
  
  PairedUnionFind tree(h + 1, w + 1); // 1 indexed

  map<pair<int, int>, bool> is_painted;

  constexpr int dx[4] = {1, 0, -1, 0};
  constexpr int dy[4] = {0, 1, 0, -1};
  
  while (q--)
    {
      int query; cin >> query;

      if (query == 1)
	{
	  int r, c; cin >> r >> c;
	  is_painted[{r, c}] = true;

	  for (int i = 0; i < 4; ++i)
	    {
	      int nx = r + dx[i];
	      int ny = c + dy[i];
		  
	      if (1 <= nx and nx <= h and 1 <= ny and ny <= w) // 1 indexed
		{
		  if (is_painted[{nx, ny}]) tree.merge({r, c}, {nx, ny});
		}
	    }
	}

      if (query == 2)
	{
	  int r_a, c_a, r_b, c_b; cin >> r_a >> c_a >> r_b >> c_b;

	  if (is_painted[{r_a, c_a}] and is_painted[{r_b, c_b}] and tree.same({r_a, c_a}, {r_b, c_b}))
	    {
	      cout << "Yes" << endl;
	    }
	  
	  else cout << "No" << endl;
	}
    }
  
  return 0;
}
