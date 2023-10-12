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
  
  string s; cin >> s;

  for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == 'a' or s[i] == 'e' or s[i] == 'o' or 'i' == s[i] or s[i] == 'u')
	{
	  cout << "";
	}
      else cout << s[i];
    }

  cout << endl;

  return 0;
}
