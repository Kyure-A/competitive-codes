/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;

class UnionFind
{
public:
  vector<long long> parent;
  vector<long long> set_size;

  // constructor
  UnionFind (long long n): parent(n), set_size(n, 1LL)
  {
    for (long long i = 0; i < n; ++i) parent[i] = i;
  }
  
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

  bool samep (long long x, long long y)
  {
    return root(x) == root(y);
  }

  long long size(long long x)
  {
    return set_size[root(x)];
  }

};

signed main ()
{
  int n, m; cin >> n >> m;
  UnionFind tree(n + 1);
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      tree.merge(a, b);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

  int count = 0;

  vector<vector<bool>> removed(n + 1, vector<bool>(n + 1, false));
  
  for (int i = 1; i <= n; ++i)
    {
      for (auto v : graph[i])
	{
	  if (tree.samep(i, v) and !(removed[i][v] or removed[v][i]))
	    {
	      count++;
	      removed[i][v] = true;
	      removed[v][i] = true;
	    }
	}
    }
  
  cout << count << endl;

  return 0;
}
