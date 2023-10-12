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

namespace kyre
{
  using namespace std;

  class RunLength
  {
  public: 
    string str;
    vector<pair<char, int>> encoded;
    map<char, vector<int>> index;
    bool is_encoded = false;
    
    RunLength(string s) : str(s) {}

    void encode ()
    {
      int count = 0;
      for (int left = 0; left < (int) str.size();)
	{
	  int right = left + 1;
	  for (; right < (int) str.size() and str[left] == str[right]; right++) {};
	  encoded.emplace_back({str[left], right - left});
	  left = right;
	  index[str[left]].emplace_back(count);
	  count++;
	}
      
      is_encoded = true;
    }

    vector<pair<char, int>> data()
    {
      if (is_encoded) encode();
      return encoded;
    }

    vector<int> find(const char c)
    {
      if (is_encoded) encode();
      return index[c];
    }
    
  };
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  string s; cin >> s;

  kyre::RunLength rle(s);

  bool period_existence = false;
  if (!rle.find('-').empty()) period_existence = true;

  int max_o = -1;
  
  for (auto i : rle.find('o'))
    {
      max_o = max(rle.data()[i].second, max_o);
    }

  if (period_existence) cout << max_o << endl;
  else cout << -1 << endl;
  
  return 0;
}
