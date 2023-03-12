/* ------------------------------ include ------------------------------ */
#include <bits/stdc++.h>
// #include <atcoder/modint>
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
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  string s(n, ' ');

  if (b > c)
    {
      swap(b, c);
      swap(a, d);
    }

  if (c - b > a || c - b > d + 1)
    { 
      cout << "No" << endl;
      return 0;
    }
  
  for (int i = 0; i < n; ++i) {
    
    if (i == 0)
      {
	s[i] = 'X';
      }
    
    else if (i == n - 1)
      {
	s[i] = 'Y';
      }
    
    else if (i % 2 == 1 && b > 0)
      {
	s[i] = 'Y';
	b--;
      }
    
    else if (i % 2 == 0 && c > 0)
      {
	s[i] = 'X';
	c--;
      }
    
    else if (a > 0)
      {
	s[i] = 'X';
	a--;
      }
    
    else if (d > 0)
      {
	s[i] = 'Y';
	d--;
      }
    
    else
      {
	cout << "No" << endl;
	return 0;
      }
  }

  cout << "Yes" << endl;
  return 0;
}
