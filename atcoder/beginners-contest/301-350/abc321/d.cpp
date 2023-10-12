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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m, p; cin >> n >> m >> p;
  vector<int> a(n);
  vector<int> b(m); rep(i, m) cin >> b[i]; sort(all(b));
  vector<int> sum(m); sum[0] = b[0];
  
  for (int i = 1; i < m; ++i)
    {
      sum[i] = sum[i - 1] + b[i];
    }

  long long answer = 0;
  
  for (int i = 0; i < n; ++i) // a を固定して a + b[i] が p をこえるか
    {
      int left = 0, right = m;

      while (left <= right)
	{
	  int mid = left + (right - left) / 2;
	  if (a[i] + b[mid] >= p) right = mid - 1;
	  else left = mid + 1;
	}

      answer += a[i] * (m - left) + sum[m - left] + p * left;
    }

  cout << answer << endl;
  
  return 0;
}
