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

bool checkConditions(const vector<string>& strings)
{
  for (int i = 0; i < strings.size() - 1; i++)
    {
      const string& current = strings[i];
      const string& next = strings[i + 1];
      int diffCount = 0;

      for (int j = 0; j < current.length(); j++)
	{
	  if (current[j] != next[j])
	  diffCount++;
            
	if (diffCount > 1)
	  return false;
	}
    }

  return true;
}

bool canArrangeStrings(const vector<string>& strings)
{
  vector<string> permutation = strings;

  do {
    if (checkConditions(permutation)) return true;
  } while (next_permutation(permutation.begin(), permutation.end()));

  return false;
}

signed main() {
  
  int n, m; cin >> n >> m;

  vector<string> strings(n); rep(i, n) cin >> strings[i];
  sort(strings.begin(), strings.end());

  if (canArrangeStrings(strings)) cout << "Yes" << endl;
  
  else cout << "No" << endl;

  return 0;
}
