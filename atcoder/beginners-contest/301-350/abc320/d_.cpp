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
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

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
    int x;
    int y;
  };
  
  vector<vector<Edge>> graph(n);
  
  for (int i = 0; i < m; ++i)
    {
      int a, b, x, y; cin >> a >> b >> x >> y;
      a--; b--;
      graph[a].push_back({b, x, y});
      graph[b].push_back({a, - x, - y});
    }

  struct Position {
    int x;
    int y;
    set<pair<int, int>> xy;
    bool is_valid = false;

    void insert(int x, int y)
    {
      xy.insert({x, y});
    }
  };
  
  vector<Position> pos(n);
  pos[0].x = 0;
  pos[0].y = 0;
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

	  pos[near_v.to].x = pos[v].x + near_v.x;
	  pos[near_v.to].y = pos[v].y + near_v.y;
	  pos[near_v.to].is_valid = true;
	  pos[near_v.to].insert(pos[near_v.to].x, pos[near_v.to].y);
	}
    }

  for (auto p : pos)
    {
      if (p.is_valid and p.xy.size() == 1) cout << p.x << " " << p.y << endl;
      else cout << "undecidable" << endl;
    }
  
  return 0;
}
