/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
typedef long long i64;
typedef long long int64;
typedef long long ll;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;

// https://qiita.com/ofutonton/items/c17dfd33fc542c222396

struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

signed main ()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;
  UnionFind tree(n);
  vector<vector<int>> graph(n + 1);

  for (int i = 0; i < m; ++i)
    {
      int u, v; cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
      tree.unite(u, v);
    }

  int deg1 = 0;
  int deg2 = 0;

  vector<int> deg1_v;
  
  for (int i = 1; i <= n; ++i)
    {
      if (graph[i].size() == 1)
	{
	  deg1++;
	  deg1_v.push_back(i);
	}
      else if (graph[i].size() == 2) deg2++;
    }

  if (deg1 == 2 and deg2 == n - 2)
    {
      if (tree.root(deg1_v[0]) == tree.root(deg1_v[1])) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  else cout << "No" << endl;

  return 0;
}
