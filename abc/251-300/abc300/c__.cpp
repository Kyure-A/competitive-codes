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

// ぷせうどさんありがとう(https://twitter.com/pseudo_thermal/status/1654092336329289729)

template <typename T> struct UnionFind
{
  vector<T> coordinates;
  vector<int> par;
  vector<int> set_size;
  
  // constructor
  UnionFind(vector<T> a)
  {
    sort(a.begin(), a.end());
    unique(a.begin(), a.end());
    coordinates = a;
    par = vector<int>(a.size(), -1);
    set_size = vector<int>(a.size(), 1);
  }
 
  int pos(const T &a)
  {
    return lower_bound(coordinates.begin(), coordinates.end(), a) - coordinates.begin();
  }
 
  int root(const T &a)
  {
    int pa = pos(a);
    int ans = pa;
    while (par[ans] != -1) ans = par[ans];
    if (ans != pa) par[pa] = ans;
    return ans;
  }
 
  bool merge(const T &a, const T &b)
  {
    int ra = root(a);
    int rb = root(b);
    if (ra == rb) return false;
    if(set_size[ra] > set_size[rb]) swap(ra, rb);
    set_size[ra] += set_size[rb];
    par[rb] = ra;
    return true;
  }

  int size(const T &a)
  {
    return set_size[root(a)];
  }
  
  bool same(const T &a, const T &b)
  {
    int ra = root(a);
    int rb = root(b);
    if (ra == rb) return true;
    return false;
  }
};

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  vector<vector<char>> c(h, vector<char>(w)); rep(i, h) rep(j, w) cin >> c[i][j];
  vector<pair<int, int>> pos; rep(i, h) rep(j, w) pos.push_back({i, j});
  UnionFind tree(pos);
  
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
