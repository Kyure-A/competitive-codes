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
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s; cin >> s;
  int n = s.size();

  long long answer = 0;
  
  for (int bit = 0; bit < (1 << n); ++bit)
    {
      string s_sub = "";
      for (int i = 0; i < n; ++i)
	{
	  if (bit & (1 << i))
	    {
	      s_sub += s[i];
	    }
	}
      
      long long tmp = stoll(s_sub);
      answer += tmp;
    }

  // s.size() * 2 の文字列を作って + が入るか入らないかの空白を用意して bit 全探索で選ぶと良さそう
  // 空白は無視して文字列を結合して + でパースするだけの関数を作るだけでいい
  
  cout << answer << endl;

  return 0;
}
