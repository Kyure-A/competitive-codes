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
  int n, m; cin >> n >> m;
  vector<vector<int>> Graph(n);
  
  for (int i = 0; i < m; ++i)
    {
      int a, b; cin >> a >> b;
      --a;
      --b;
      Graph[a].push_back(b);
      Graph[b].push_back(a);
    }

  int result = 0;
  
  for (int v = 0; v < n; ++v)
    {
      int count = 0;
      for (auto near_v : Graph[v])
	{
	  if (v > near_v) count++; 
	}

      if (count == 1) result++;
    }

  cout << result << endl;

  return 0;
}
