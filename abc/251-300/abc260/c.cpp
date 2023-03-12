/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/all>
// #include <boost/multiprecision/cpp_int.hpp>
/* ------------------------------  using  ------------------------------ */
using namespace std;
// using namespace atcoder;
// using namespace boost::multiprecision;
/* ------------------------------  define ------------------------------ */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
// #define int long long
/* ------------------------------ function ------------------------------ */
template<typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
/* ------------------------------  const  ------------------------------ */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;
/* ------------------------------  code   ------------------------------ */

unsigned long long convertjewels (unsigned long long bluejewels, unsigned long long redjewels, int n, int x, int y)
{
  if (n - 1 > 0)
    {
      bluejewels += redjewels * x * y;
      redjewels += bluejewels * (x + 1);
      n--;
      return convertjewels(bluejewels, redjewels, n, x, y);
    }
  else return bluejewels;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, x, y; cin >> n >> x >> y;
  unsigned long long redjewels = 1;
  unsigned long long bluejewels = 0;

  cout << convertjewels(bluejewels, redjewels, n, x, y) << endl;

  return 0;
}
