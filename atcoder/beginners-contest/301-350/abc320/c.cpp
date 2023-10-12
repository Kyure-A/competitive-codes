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
  
  int m; cin >> m;
  vector<string> s(3); rep(i, 3) cin >> s[i];
  vector<vector<int>> bucket(3, vector<int>(10, 0));

  for (int x = 0; x < 3; ++x)
    {
      for (int i = 0; i < m; ++i)
	{
	  bucket[x][ctoi(s[i])]++;
	}
    }

  return 0;
}
