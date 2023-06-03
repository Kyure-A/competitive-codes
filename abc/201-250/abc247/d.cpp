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
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int q; cin >> q;
  deque<pair<int, int>> cylinder;

  while (q--)
    {
      int query; cin >> query;

      if (query == 1)
	{
	  int x, c; cin >> x >> c;
	  
	  if (!cylinder.empty() and cylinder.back().first == x) cylinder.back().second += c;
	  else cylinder.emplace_back(make_pair(x, c));
	}

      else if (query == 2)
	{
	  int c; cin >> c;
	  long long answer = 0;

	  while (c > 0)
	    {
	      if (c - cylinder.front().second >= 0)
		{
		  answer += cylinder.front().first * cylinder.front().second;
		  c -= cylinder.front().second;
		  cylinder.pop_front();
		}

	      else if (c - cylinder.front().second < 0)
		{
		  cylinder.front().second -= c;
		  answer += cylinder.front().first * c;
		  c = 0;
		}
	    }

	  cout << answer << "\n";
	}
    }

  return 0;
}
