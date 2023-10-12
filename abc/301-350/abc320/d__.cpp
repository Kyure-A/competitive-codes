#include <bits/stdc++.h>
using namespace std;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  // 初回は人 1 の情報 (0, 0) しかないので 1 からたどる
  // 人 A_i からみて B_i は x軸正方向に X_i, y軸正方向に Y_i 離れた位置
  // <->
  // 人 B_i からみて A_i は x軸正方向に -X_i, y軸正方向に -Y_i 離れた位置

  struct Edge {
    int to;
    long long x;
    long long y;
  };
  
  vector<vector<Edge>> graph(n);
  
  for (int i = 0; i < m; ++i)
    {
      int a, b;
      long long x, y;
      cin >> a >> b >> x >> y;
      a--; b--;
      graph[a].push_back({b, x, y});
      graph[b].push_back({a, - x, - y});
    }

  struct Position {
    long long x;
    long long y;
    bool is_valid = false;
  };
  
  vector<Position> pos(n);
  pos[0].x = 0LL;
  pos[0].y = 0LL;
  pos[0].is_valid = true;  

  // bfs
  
  vector<bool> seen(n, false); // -1 の場合は未訪問
  queue<int> que; // first in first out

  seen[0] = 0; que.emplace(0); 

  while (!que.empty())
    {
      auto v = que.front(); que.pop();

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v])
	{
	  if (seen[near_v.to]) continue;
	  
	  seen[near_v.to] = true;
	  que.emplace(near_v.to);

	  pos[near_v.to] = {pos[v].x + near_v.x, pos[v].y + near_v.y, true};
	}
    }

  for (auto p : pos)
    {
      if (p.is_valid) cout << p.x << " " << p.y << endl;
      else cout << "undecidable" << endl;
    }
  
  return 0;
}
