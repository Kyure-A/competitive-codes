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

using boost::multiprecision::cpp_int;

cpp_int str_to_cpp_int(string s)
{
  cpp_int res = 0;
  for (char c : s) res = res * 10 + (c - '0');
  return res;
}

string to_string(cpp_int num) {
  return boost::lexical_cast<string>(num);
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int q; cin >> q;
  string s = "1"; 
  
  while (q--)
    {
      int query; cin >> query;

      if (query == 1)
	{
	  string x; cin >> x;
	  s += x;
	  cpp_int s_int = str_to_cpp_int(s);
	  s = to_string(s_int);
	}

      if (query == 2)
	{
	  s[0] = '0';
	  cpp_int s_int = str_to_cpp_int(s);
	  s = to_string(s_int);
	}

      if (query == 3)
	{
	  cpp_int s_int = str_to_cpp_int(s);
	  s_int %= _MOD;
	  cout << s_int << endl;
	}
    }

  return 0;
}
