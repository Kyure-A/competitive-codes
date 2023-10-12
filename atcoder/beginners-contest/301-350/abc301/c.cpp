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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s; cin >> s;
  string t; cin >> t;

  map<char, int> seq_1, seq_2;

  int n = s.size();
  
  for (int i = 0; i < n; ++i)
    {
      seq_1[s[i]]++;
      seq_2[t[i]]++;
    }

  bool can_win = true;
  
  for (auto alphabet : {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'})
    {
      if (seq_1[alphabet] > seq_2[alphabet] and seq_1[alphabet] <= seq_2[alphabet] + seq_2['@'])
	{
	  if (alphabet == 'a' or alphabet == 't' or alphabet == 'c' or alphabet == 'o' or alphabet == 'd' or alphabet == 'e' or alphabet == 'r')
	    {
	      seq_2['@'] -= (seq_1[alphabet] - seq_2[alphabet]);
	    }
	  else can_win = false;
	}
      else if (seq_2[alphabet] > seq_1[alphabet] and seq_2[alphabet] <= seq_1[alphabet] + seq_1['@'])
	{
	  if (alphabet == 'a' or alphabet == 't' or alphabet == 'c' or alphabet == 'o' or alphabet == 'd' or alphabet == 'e' or alphabet == 'r')
	    {
	      seq_1['@'] -= (seq_2[alphabet] - seq_1[alphabet]);
	    }
	  else can_win = false;
	}
      else if (seq_1[alphabet] == seq_2[alphabet]) continue;
      else
	{
	  can_win = false;
	}
    }

  if (can_win) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
