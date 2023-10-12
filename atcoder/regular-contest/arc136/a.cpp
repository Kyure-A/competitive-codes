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
#define ctoi(char) int(char) - '0'
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
// #define int long long
/* ------------------------------ function ------------------------------*/
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
/* ------------------------------  const  ------------------------------ */
constexpr double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

// https://algo-logic.info/run-length/
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

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; string s; cin >> n >> s;

  string AtoBB = "";
  
  for (int i = 0; i < n; ++i)
    {
      if (s[i] == 'A') AtoBB += "BB";

      else AtoBB += s[i];
    }
  
  vector<pair<char, int>> BtoAA = encode(AtoBB);
  
  
  for (int i = 0; i < (int) BtoAA.size(); ++i)
    {
      if (BtoAA[i].first == 'B')
	{
	  int countB = BtoAA[i].second % 2;
	  int countA = (BtoAA[i].second - countB) / 2;
	  rep(i, countA) cout << "A";
	  rep(i, countB) cout << "B";
	}
      
      else if (BtoAA[i].first == 'C')
	{
	  int countC = BtoAA[i].second;
	  rep(i, countC) cout << "C";
	}
      }
  
  return 0;  
}
