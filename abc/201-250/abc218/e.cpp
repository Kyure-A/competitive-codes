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
constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

class UnionFind
{
public:
  vector<long long> parent;
  vector<long long> set_size;

  // // constructor
  // UnionFind (long long n): parent(n), set_size(n, 1LL)
  // {
  //   for (long long i = 0; i < n; ++i) parent[i] = i;
  // }
  
  void init(long long n)
  {
    parent.resize(n);
    set_size.assign(n, 1LL);
    for (long long i = 0; i < n; ++i) parent[i] = i; 
  }

  long long root (long long x) // find (path halving)
  {
    while (parent[x] != x)
      {
	parent[x] = parent[parent[x]];
	x = parent[x];
      }

    return x;
  }

  bool merge (long long x, long long y) // union by size
  {
    long long rx = root(x);
    long long ry = root(y);

    if (rx == ry) return false;
    else if (set_size[rx] < set_size[ry]) swap(rx, ry); // root(y) のほうがデカいときも merge できるように逆にする
    
    // Operations
    parent[ry] = rx;
    set_size[rx] += set_size[ry];
    return true;
  }

  bool same (long long x, long long y)
  {
    return root(x) == root(y);
  }

  long long size(long long x)
  {
    return set_size[root(x)];
  }

};

struct Edge
{
  int u;
  int v;
  long long cost;
};

bool compare_edges(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }

struct Kruskal
{
  UnionFind tree;
  vector<long long> can_destructed_edges;
  vector<Edge> edges;
  int V;
  
  Kruskal(const vector<Edge> &_edges, int _V) : edges(_edges), V(_V) { init(); }
  
  void init()
  {
    sort(edges.begin(), edges.end(), compare_edges);
    tree.init(V);

    for (auto e : edges)
      {
	if (!tree.same(e.u, e.v)) tree.merge(e.u, e.v);
	  
	else can_destructed_edges.push_back(e.cost);
      }
  }
  
};

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // グラフが連結である最小の条件を考えればよさそう
  
  int n, m; cin >> n >> m;
  vector<Edge> edges(m);

  long long cost_sum = 0;
  
  for (int i = 0; i < m; ++i)
    {
      int a, b;
      long long c;
      cin >> a >> b >> c;
      a--; b--;
      edges[i] = {a, b, c};
    }

  Kruskal krs(edges, n);
  
  for (auto e : krs.can_destructed_edges) cost_sum = max(cost_sum, cost_sum + e);

  cout << cost_sum << endl;
  
  return 0;
}
