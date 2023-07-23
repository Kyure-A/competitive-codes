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
  string s; cin >> s;

  bool count[3] = {false};

  for (int i = 0; i < n; ++i)
    {
      if (s[i] == 'A') count[0] = true;
      if (s[i] == 'B') count[1] = true;
      if (s[i] == 'C') count[2] = true;

      if (count[0] and count[1] and count[2])
	{
	  cout << i + 1 << endl;
	  return 0;
	}
    }						  

  return 0;
}
