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

  int n, m, h, k; cin >> n >> m >> h >> k;
  string s; cin >> s;

  struct xy {
    int x, y;
  };
  
  set<pair<int, int>> items;

  for (int i = 0; i < m; ++i)
    {
      int x, y; cin >> x >> y;
      items.insert({x, y});
    }

  // move
    
  xy takahashi = {0, 0};
  
  int takahashi_health = h;

  bool is_moving = true;
  
  for (int i = 0; i < n; ++i)
    {
      if (s[i] == 'R')
	{
	  takahashi.x++;
	  takahashi_health--;
	}
      
      else if (s[i] == 'L')
	{
	  takahashi.x--;
	  takahashi_health--;
	}
      
      else if (s[i] == 'U')
	{
	  takahashi.y++;
	  takahashi_health--;
	}
      
      else // s[i] == 'D'
	{
	  takahashi.y--;
	  takahashi_health--;
	}

      if (takahashi_health < 0)
	{
	  is_moving = false;
	  break;
	}
      
      if (takahashi_health < k and items.count({takahashi.x, takahashi.y}) != 0)
	{
	  takahashi_health = k;
	  items.erase({takahashi.x, takahashi.y});
	}

      cout << takahashi.x << " " << takahashi.y << endl;
    }

  if (is_moving) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
