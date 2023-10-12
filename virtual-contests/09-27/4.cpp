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

void question (int a, int b, int c, int d)
{
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
}

void answer (int x, int y)
{
  cout << "! " << x << " " << y << endl;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  
  int left = 1, right = n;

  while (left <= right) // x を しぼる
    {
      int mid = left + (right - left) / 2;
      question(left, mid, 1, n);
      int t; cin >> t;

      if (t < mid - left + 1) right = mid - 1;
      else left = mid + 1;
    }
  
  int left2 = 1, right2 = n;

  while (left2 <= right2) // y をしぼる
    {
      int mid = left2 + (right2 - left2) / 2;
      question(1, n, left2, mid);
      int t; cin >> t;

      if (t < mid - left2 + 1) right2 = mid - 1;
      else left2 = mid + 1;
    }

  answer(left, left2);
  
  return 0;
}
