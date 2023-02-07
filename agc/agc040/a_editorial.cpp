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

// reference:
// https://atcoder.jp/contests/agc040/submissions/37740679
// https://atcoder.jp/contests/agc040/submissions/37736509

signed main ()
{
  string s;
  cin >> s;

  int n = s.length();
  i64 answer = 0;
  
  vector<int> leftparen(n, 0);
  vector<int> rightparen(n, 0);
  rep(i, n) if (s[i] == '<') leftparen[i + 1] = leftparen[i] + 1;
  per(i, n) if (s[i] == '>') rightparen[i] = rightparen[i + 1] + 1;
  rep(i, n) answer += max(leftparen[i], rightparen[i]);

  cout << answer << endl;

  return 0;
}
