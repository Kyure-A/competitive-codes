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

bool is_palindrome (string s)
{
  int n = s.size();
  bool cond = true;
  for (int i = 0; i < n; ++i)
    {
      if (s[i] != s[n - i - 1]) cond = false;
    }

  return cond;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.size();

  int answer = 0;
  
  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
	{
	  if (j < i) continue;
	  string substr = s.substr(i, j - i);
	  if (is_palindrome(substr)) answer = max(answer, (int)substr.size());
	}
    }

  if (is_palindrome(s)) answer = max(answer, (int)s.size());

  cout << answer << endl;
  
  return 0;
}
