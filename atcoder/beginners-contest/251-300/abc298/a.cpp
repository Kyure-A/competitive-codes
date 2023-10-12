#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

constexpr double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
/* ------------------------------ code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  string s; cin >> s;
  
  int o_count = 0;
  int x_count = 0;
  
  for (int i = 0; i < n; ++i)
    {
      if (s[i] == 'o') o_count++;
      else if (s[i] == 'x') x_count++;
    }

  if (o_count >= 1 and x_count == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
