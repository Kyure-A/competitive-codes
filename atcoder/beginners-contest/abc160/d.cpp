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


signed main ()
{
  int n, x, y; cin >> n >> x >> y;
  vector<vector<int>> graph(n + 1);

  for (int i = 1; i <= n; ++i)
    {
      if (i != x or i != y)
	{
	  graph[i].push_back(i + 1);
	  graph[i + 1].push_back(i);
	}
      
      else if (i == x) 
	{
	  for (int i = 1; abs((x + i) - y) > 0; ++i)
	    {
	      graph[x].push_back(x + i);
	      graph[x + i].push_back(x);
	    }
	  
	  graph[x].push_back(y);
	}
      
      else if (i == y)
	{
	  for (int i = 1; abs(x - (y - i)) > 0; ++i)
	    {
	      graph[y].push_back(y - 1);
	      graph[y - i].push_back(y);
	    }
	  
	  graph[y].push_back(x);
	}
    }

  // BFS のためのデータ構造
  vector<int> dist(n + 1, -1); // 全頂点を「未訪問」に初期化
  queue<int> que;

  // 初期条件 (頂点 1 を初期ノードとする)
  dist[1] = 0;
  que.push(1); // 1 を橙色頂点にする

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty())
    {
      int v = que.front(); // キューから先頭頂点を取り出す
      que.pop();

      // v から辿れる頂点をすべて調べる
      for (int nv : graph[v])
      {
	if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない
	
	// 新たな白色頂点 nv について距離情報を更新してキューに追加する
	dist[nv] = dist[v] + 1;
	que.push(nv);
      }
    }

  vector<int> k_ans(n);
  
  for (int i = 1; i <= n; ++i) k_ans[dist[i]]++;

  for (int i = 1; i < n; ++i) cout << k_ans[i] << endl;

  return 0;
    }
