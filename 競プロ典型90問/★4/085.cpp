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
  
  long long k; cin >> k;

  vector<long long> divisors;
  
  // 約数列挙
  for (int d = 1; d <= floor(sqrt(k)); ++d)
    {
      if (k % d == 0)
	{
	  long long a = d;
	  long long b = k / d;
	  divisors.push_back(a);
	  if (a != b) divisors.push_back(b);
	}
    }


  int answer = 0;
  
  for (int i = 0; i < divisors.size(); ++i)
    {
      for (int j = i; j < divisors.size(); ++j)
	{
	  long long a = divisors[i];
	  long long b = divisors[j];
	  
	  if ((k / a) < b) continue; // ?
	  if (k % (a * b) != 0ll) continue;
	  
	  long long c = k / (a * b);

	  if (b <= c) answer++;
	}
    }

  cout << answer <<endl;

  return 0;
}
