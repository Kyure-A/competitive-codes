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

bool is_prime (long long x)
{
  for (int i = 2; i * i <= x; ++i)
    {
      if (x % i == 0)
	{
	  return false;
	}
    }
  return true;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  long long n; cin >> n;
  vector<long long> prime_numbers;
  
  for (int i = 2; i * i <= n; ++i)
    {
      if (n % i == 0)
	{
	  if (is_prime(i)) prime_numbers.push_back(i);
	  if (is_prime(n / i)) prime_numbers.push_back(n / i);
	}
    }
  
  bool cond = false;
  
  for (int i = 0; i < prime_numbers.size(); ++i)
    {
      for (int j = 0; j < prime_numbers.size(); ++j)
	{
	  if (prime_numbers[i] == prime_numbers[j]) continue;

	  if (prime_numbers[i] * prime_numbers[i] * prime_numbers[j] == n)
	    {
	      cond = true;
	    }
	}
    }

  //  for (auto x : prime_numbers) cout << x << endl;
  
  cout << (cond ? "Yes" : "No") << endl;
  
  return 0;
}
