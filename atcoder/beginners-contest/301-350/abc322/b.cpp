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

bool is_prefix (string s, string t)
{
  bool result = true;

  for (int i = 0; i < (int)s.size(); ++i)
    {
      if (s[i] != t[i]) result = false;
    }

  return result;
}

bool is_suffix (string s, string t)
{
  bool result = true;
  int diff = t.size() - s.size();
  for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] != t[i + diff]) result = false;
    }

  return result;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m; // s.size() == n, t.size() == m;
  string s, t; cin >> s >> t;

  if (is_prefix(s, t) and is_suffix(s, t)) cout << 0 << endl;
  else if (is_prefix(s, t)) cout << 1 << endl;
  else if (is_suffix(s, t)) cout << 2 << endl;
  else cout << 3 << endl;
  
  return 0;
}
