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

template <typename T> struct UnionFind {
  vector<T> coordinates;
  vector<int> parent;
  vector<int> size;
  
  UnionFind(vector<T> vec)
  {
    sort(vec.begin(), vec.end());
    unique(vec.begin(), vec.end());
    coordinates = vec;
    parent = vector<int>(vec.size(), -1);
    size = vector<int>(vec.size(), 1);
  }

  int position(const T &x)
  {
    return lower_bound(coordinates.begin(), coordinates.end(), x) - coordinates.begin();
  }

  int root(const T &x)
  {
    int px = position(x);
    int ans = px;
    
    while (parent[ans] != -1)
      {
	ans = parent[ans];
      }
    
    if (ans != px) parent[px] = ans;
    
    return ans;
  }

  bool merge(const T &x, const T &y)
  {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return false;
    if(size[rx] > size[ry]) swap(rx, ry);
    size[rx] += size[ry];
    parent[ry] = rx;
    return true;
  }

  bool same(const T &x, const T &y)
  {
    return root(x) == root(y);
  }
};

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  int q; cin >> q;

  vector<pair<int, int>> pos;
  rep(i, h + 1) rep(j, w + 1) pos.emplace_back(i, j);
  
  UnionFind tree(pos); // 1 indexed
 
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
 
	  if (r_a == r_b and c_a == c_b and is_painted[{r_a, c_a}])
	    {
	      cout << "Yes" << endl;
	    }
	  
	  else if ((r_a != r_b or c_a != c_b) and tree.same({r_a, c_a}, {r_b, c_b}))
	    {
	      cout << "Yes" << endl;
	    }
	  
	  else cout << "No" << endl;
	}
    }

  return 0;
}
