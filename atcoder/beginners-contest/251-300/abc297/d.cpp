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

long long gcd(long long a, long long b)
{
  long long count = -1;
  
  while (b != 0)
    {
      long long r = a % b;
      count += a / b;
      a = b;
      b = r;
    }
  
  return count;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long a, b; cin >> a >> b;

  cout << gcd(a, b) << endl;

  return 0;
}
