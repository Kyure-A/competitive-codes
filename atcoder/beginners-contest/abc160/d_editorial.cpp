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
  --x; --y; // 正規化
  // BFS のためのデータ構造
  vector<vector<int>> dist(n, vector<int>(n, -1)); // (i, j) の最短距離を格納する配列
  for (int i = 0; i < n; ++i)
    {
      queue<int> que; // fifo
      que.push(i);
      dist[i][i] = 0; // (i, j) 間の距離, (i, i) なら当然0 start
      // BFS 開始 (キューが空になるまで探索を行う)
      while (!que.empty())
	{
	  auto v_i = que.front(); que.pop();// キューから先頭頂点(i)を取り出す
	  vector<int> near_vertex_i;
	    
	  // この下二行は同時に満たされることがほとんど、つまり大体の場合で
	  // if (大体の場合) near_vertex_i.push_back(v - 1); near_vertex_i.push_back(v + 1); 
	  if (v_i > 0) near_vertex_i.push_back(v_i - 1);
	  if (v_i < n - 1) near_vertex_i.push_back(v_i + 1);
	    
	  // x と y の間に辺があるだけで、なんか変な繋がり方をして x と y はつながっていることは図からわかっている
	  if (v_i == x) near_vertex_i.push_back(y);
	  if (v_i == y) near_vertex_i.push_back(x);
	    
	  // i (v_i) から辿れる頂点をすべて調べる
	  for (auto j : near_vertex_i)
	    {
	      if (dist[i][j] == -1) // 未訪問なら
		{
		  dist[i][j] = dist[i][v_i] + 1;
		  que.push(j); // 次は j をたずねる
		}
		  
	    }
	}
    }

  vector<int> result(n, 0);
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < n; ++j)
	{
	  result[dist[i][j]]++;
	}
    }

  for (int i = 1; i < n; ++i) cout << result[i] << endl; // k = 1 から n - 1 までなので i は 1 から始まる

    return 0;
  
}
