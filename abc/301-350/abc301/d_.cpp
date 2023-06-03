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

vector<long long> get_possible_numbers(const string& s)
{
  int n = s.size();
  int q_count = count(s.begin(), s.end(), '?');
  vector<long long> res(1 << q_count);
  
  for (int i = 0; i < (1 << q_count); i++)
    {
      bitset<60> b(i);
      int idx = 0;
      long long num = 0;
      
      for (int j = 0; j < n; j++)
	{
	  if (s[j] == '0')
	    {
	      num = num * 2;
	    }
	  
	  else if (s[j] == '1')
	    {
	      num = num * 2 + 1;
	    }
	  else
	    {
	      num = num * 2 + b[idx];
	      idx++;
	    }
	}
      
      res[i] = num;
    }
  
  sort(res.begin(), res.end());
  return res;
}

long long solve(const string& s, long long n)
{
  vector<long long> possible_numbers = get_possible_numbers(s);
  
  if (possible_numbers.empty()) {
    return -1;
  }
  
  long long ans = -1;
  for (long long num : possible_numbers)
    {
      if (num <= n)
	{
	  ans = max(ans, num);
	}
      else
	{
	  break;
	}
    }
  return ans;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s;
  long long n;
  cin >> s >> n;
  cout << solve(s, n) << endl;
  return 0;
}
