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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool red[100 + 1] = {false};
  bool blue[100 + 1] = {false};

  int answer = 0;
  
  for (int i = a; i <= b; ++i) red[i] = true;
  
  for (int i = c; i <= d; ++i) blue[i] = true;
  
  for (int i = 0; i <= 100; ++i) if (red[i] and blue[i]) answer++;

  cout << max(0, answer - 1) << endl;
  
  return 0;
}
