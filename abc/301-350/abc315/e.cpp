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
  
  int n; cin >> n;
  vector<vector<int>> book(n);

  for (int i = 0; i < n; ++i)
    {
      int c; cin >> c;
      
      for (int j = 0; j < c; ++j)
	{
	  int p; cin >> p;
	  p--;
	  book[i].push_back(p);
	}
    }
  
  vector<int> result;
  
  auto dfs = [&](auto&& self, int v, int prv) -> void {
    for (int near_v : book[v])
      {
	if (near_v == prv) continue;
	self(self, near_v, v);
      }
    result.push_back(v + 1);
  };

  dfs(dfs, 0, 0);

  for (auto x : result)
    {
      cout << x << " ";
    }

  cout << endl;

  return 0;
}
