/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all>
// using namespace atcoder

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
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool flag = false;
  
  if ((s[0] == 'B' or s[s.length() - 1] == 'A') and (s.length() != 2)) flag = true;
  else if (s.length() == 2 and (s == "AA" or s == "BB")) flag = true; 
  
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
