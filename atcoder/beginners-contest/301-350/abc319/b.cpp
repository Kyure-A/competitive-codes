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
  
  int n; cin >> n;
  vector<int> j;
  
  for (int i = 1; i <= 9; ++i)
    {
      if (n % i == 0) j.push_back(i); 
    }

  for (int i = 0; i <= n; ++i)
    {
      vector<int> baisuu;
      for (auto x : j)
	{
	  if (i % (n / x) == 0) baisuu.push_back(n / x);
	}
      sort(all(baisuu));

      if (baisuu.size() == 0) cout << "-";
      else cout << baisuu[0];
    }

  cout << endl;

  return 0;
}
