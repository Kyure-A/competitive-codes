#include <bits/stdc++.h>
using namespace std;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
using int64 = long long;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  
  bool cond = true;

  for (int i = 0; i < (int)s.size(); ++i)
    {
      if ((i + 1) % 2 == 0 and s[i] == '1') cond = false;
    }

  if (cond) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
