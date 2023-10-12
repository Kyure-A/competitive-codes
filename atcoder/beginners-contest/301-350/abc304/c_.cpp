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

namespace kyre
{
  using namespace std;

  long double euclideanDistance(pair<int, int> a, pair<int, int> b)
  {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
  }

  long double euclideanDistance(int a_x, int a_y, int b_x, int b_y)
  {
    return sqrt(pow(a_x - b_x, 2) + pow(a_y - b_y, 2));
  }
}

namespace kyre
{
  using namespace std;
  
  class UnionFind
  {
  public:
    vector<int> parent;
    vector<int> set_size;

    // constructor
    UnionFind (int n): parent(n), set_size(n, 1LL)
    {
      for (int i = 0; i < n; ++i) parent[i] = i;
    }
    void init(int n)
    {
      parent.resize(n);
      set_size.assign(n, 1LL);
      for (int i = 0; i < n; ++i) parent[i] = i; 
    }

    int root (int x) // find (path halving)
    {
      while (parent[x] != x)
	{
	  parent[x] = parent[parent[x]];
	  x = parent[x];
	}

      return x;
    }

    bool merge (int x, int y) // union by size
    {
      int rx = root(x);
      int ry = root(y);

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

    bool same (int x, int y)
    {
      return root(x) == root(y);
    }

    int size (int x)
    {
      return set_size[root(x)];
    }

  };
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, d; cin >> n >> d;
  vector<pair<int, int>> people(n); rep(i, n) cin >> people[i].first >> people[i].second;
  kyre::UnionFind tree(n);
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (kyre::euclideanDistance(people[i], people[j]) <= double(d))
	    {
	      tree.merge(i, j);
	    }
	}
    }

  vector<bool> is_infected(n, false);
  is_infected[0] = true;

  for (int i = 0; i < n; ++i)
    {
      if (tree.same(0, i)) is_infected[i] = true;
    }

  for (int i = 0; i < n; ++i)
    {
      if (is_infected[i]) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

  return 0;
}
