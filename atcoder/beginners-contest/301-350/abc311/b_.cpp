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
  
  int n, d; cin >> n >> d;
  vector<bitset<100>> bs(n);

  for (int i = 0; i < n; ++i)
    {
      string s; cin >> s;
      s = regex_replace(s, regex("o"), "1");
      s = regex_replace(s, regex("x"), "0");
      bs[i] = bitset<100>(s);
    }

  string x = "";
  
  for (int i = 0; i < d; ++i)
    {
      x += "1";
    }

  bitset<100> res(x);
  
  for (int i = 0; i < n; ++i)
    {
      res &= bs[i];
    }

  string str = res.to_string();

  int answer = 0;
  int pre_answer = 0;
  
  for (int i = 0; i < (int)str.size(); ++i)
    {
      if (str[i] == '1') pre_answer++;
      else
	  {
	    answer = max(pre_answer, answer);
	    pre_answer = 0;
	  }
    }

  answer = max(pre_answer, answer);

  cout << answer << endl;

  return 0;
}
