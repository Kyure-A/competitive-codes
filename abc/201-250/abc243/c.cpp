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

  int n; cin >> n;
  vector<pair<int, int>> human(n);
  rep(i, n) cin >> human[i].first >> human[i].second;
  string s; cin >> s;

  map<int, vector<int>> same_y;
  set<int> y;
  
  for (int i = 0; i < n; ++i)
    {
      same_y[human[i].second].emplace_back(i);
      y.insert(human[i].second);
    }

  string answer = "No";

  for (auto ny : y)
    {
      set<int> l;
      set<int> r;
      
      for (int j = 0; j < (int)same_y[ny].size(); ++j)
	{
	  if (s.at(same_y[ny][j]) == 'L') l.insert(human[same_y[ny][j]].first);
	  if (s.at(same_y[ny][j]) == 'R') r.insert(human[same_y[ny][j]].first);
	}
      
      if (!l.empty() and !r.empty() and *r.begin() < *l.rbegin()) answer = "Yes";
    }

  cout << answer << endl;

  return 0;
}
