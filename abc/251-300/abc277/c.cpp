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

// editorial

signed main ()
{
  int n;
  cin >> n;
  map<int, vector<int>> graph;
  for (int i = 0; i < n; ++i)
    {
      int a, b; cin >> a >> b;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

  // 頂点番号が 1 から始まっていた場合は 正規化 (デクリメントして 0-indexed に) することを忘れない！

  queue<int> que; // first in first out
  set<int> S;
  S.insert(1);
  que.push(1); // 初期化

  // Start
  while (!que.empty())
    {
      auto v = que.front(); que.pop(); // v に実質的に queue の先頭を移動

      // v に隣接している頂点をすべて調べる
      for (auto near_v : graph[v]) if (!S.count(near_v)) {S.insert(near_v); que.push(near_v);}
    }

  cout << *S.rbegin() << "\n";
  
  return 0;
}
