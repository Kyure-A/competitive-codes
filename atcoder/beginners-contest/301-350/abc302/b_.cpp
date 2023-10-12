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

bool isPairValid(pair<int, int> a_1, pair<int, int> a_2, pair<int, int> a_3, pair<int, int> a_4, pair<int, int> a_5)
{
  int dx = a_2.first - a_1.first;
  int dy = a_2.second - a_1.second;

  if (a_3.first - a_2.first != dx || a_3.second - a_2.second != dy) return false;
  if (a_4.first - a_3.first != dx || a_4.second - a_3.second != dy) return false;
  if (a_5.first - a_4.first != dx || a_5.second - a_4.second != dy) return false;

  return true;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  vector<string> s(h); rep(i, h) cin >> s[i];
  
  vector<vector<pair<int, int>>> snuke(5);
  map<char, int> converter;
  converter['s'] = 0;
  converter['n'] = 1;
  converter['u'] = 2;
  converter['k'] = 3;
  converter['e'] = 4;
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  if (s[i][j] == 's' or s[i][j] == 'n' or s[i][j] == 'u' or s[i][j] == 'k' or s[i][j] == 'e')
	    {
	      snuke[converter[s[i][j]]].push_back({i + 1, j + 1});
	    }
	}
    }
  
  // solve
  for (int i = 0; i < snuke[0].size(); ++i)
    {
      for (int j = 0; j < snuke[1].size(); ++j)
	{
	  for (int k = 0; k < snuke[2].size(); ++k)
	    {
	      for (int l = 0; l < snuke[3].size(); ++l)
		{
		  for (int m = 0; m < snuke[4].size(); ++m)
		    {
		      pair<int, int> a_1 = snuke[0][i];
		      pair<int, int> a_2 = snuke[1][j];
		      pair<int, int> a_3 = snuke[2][k];
		      pair<int, int> a_4 = snuke[3][l];
		      pair<int, int> a_5 = snuke[4][m];

		      if (isPairValid(a_1, a_2, a_3, a_4, a_5))
			{
			  cout << a_1.first << " " << a_1.second << endl;
			  cout << a_2.first << " " << a_2.second << endl;
			  cout << a_3.first << " " << a_3.second << endl;
			  cout << a_4.first << " " << a_4.second << endl;
			  cout << a_5.first << " " << a_5.second << endl;
			  return 0;
			}
		    }
		}
	    }
	}
    }

    return 0;
}
