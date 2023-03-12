/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/all>
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
/* ------------------------------  const  ------------------------------ */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;
/* ------------------------------  code   ------------------------------ */

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

  bool same (long long x, long long y)
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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;

  UnionFind tree(n + 1);
  vector<int> a(m);
  
  for (int i = 0; i < m; ++i)
    {
      cin >> a[i];
      tree.merge(a[i], a[i] + 1);
    }

  int memo = 0;
  int count = 0;

  if (m != 0)
    {
      for (int i = 1; i < n; ++i)
	{
	  if (tree.root(i) == tree.root(i + 1) and i != n - 1) memo++;
	  else if (tree.root(i) != tree.root(i + 1))
	    {
	      for (int j = i; j >= i - memo; --j)
		{
		  cout << j << " ";
		  count++;
		}
	  
	      memo = 0;
	    }

	  if (i == n - 1)
	    {
	      for (int j = i + 1; j >= i - memo; --j)
		{
		  if (count == n) break;
		  cout << j << " ";
		  count++;
		}
	    }
	}
    }

  else rep3(i, 1, n + 1) cout << i << " ";
  
  return 0;
}
