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

vector<pair<char, int>> encode(const string& str) {
  int n = (int)str.size();
  vector<pair<char, int>> ret;
  for (int l = 0; l < n;) {
    int r = l + 1;
    for (; r < n && str[l] == str[r]; r++) {};
    ret.push_back({str[l], r - l});
    l = r;
  }
  return ret;
}
/* decode: ランレングス圧縮の復元を行う
 */
string decode(const vector<pair<char, int>>& code) {
  string ret = "";
  for (auto p : code) {
    for (int i = 0; i < p.second; i++) {
      ret.push_back(p.first);
    }
  }
  return ret;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  string s; cin >> s;
  
  vector<pair<char,int>> encoded_s = encode(s);

  int max_dango = -1;
  bool period_existence = false;
  bool o_existence = false;
  
  for (int i = 0; i < (int) encoded_s.size(); ++i)
    {
      if (!o_existence and encoded_s[i].first == 'o') o_existence = true;
      if (!period_existence and encoded_s[i].first == '-') period_existence = true;
      
      if (encoded_s[i].first == 'o') max_dango = max(max_dango, encoded_s[i].second);
    }

  if (o_existence and period_existence) cout << max_dango << endl;
  else cout << -1 << endl;
  
  return 0;
}
