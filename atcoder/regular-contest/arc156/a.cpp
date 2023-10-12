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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
/* ------------------------------   code  ------------------------------ */

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t; cin >> t;

  while (t--) // 普通に読むと O(TN) でだめ
    {
      int n; string s; cin >> n >> s; // i と j が隣接していないならば i と j を二つ選んで裏返す
      
      deque<int> omote;
      deque<int> omote2;

      for (int i = 0; i < n; ++i)
	{
	  if (s[i] == '1') {omote.emplace_front(i); omote2.emplace_front(i);}
	}

      int size = omote.size();
      
      deque<int> omote3;
      deque<int> omote4;
      
      for (int i = 0; i < size; ++i)
	{
	  int omote2_back = omote2.back();
	  omote2.pop_back();
	  if (i < (size / 2)) omote3.emplace_front(omote2_back);
	  else omote4.emplace_front(omote2_back);
	}
      
      int answer[2] = {0};
      bool flag[2] = {false};

      if (size % 2 == 1) {flag[0] = true; flag[1] = true;}
      else
	{
	  for (int i = 0; i < size / 2; ++i)
	    {
	      int omote_top = omote.front(), omote_back = omote.back();
	      omote.pop_front(); omote.pop_back();
	      if (!(omote_top - omote_back >= 2)) flag[0] = true;
	      else answer[0]++;
	    }

	  if (!((double)size / 4 <= 1))
	    {
	      for (int i = 0; i < size / 4; ++i)
		{
		  int omote3_front = omote3.front(), omote3_back = omote3.back(), omote4_front = omote4.front(), omote4_back = omote4.back();
		  omote3.pop_back(); omote3.pop_front(); omote4.pop_back(); omote4.pop_front();
		  if (!(omote3_front - omote3_back >= 2)) flag[1] = true;
		  else answer[1]++;
		  if (!(omote4_front - omote4_back >= 2)) flag[1] = true;
		  else answer[1]++;
		}
	    }
	  
	  else flag[1] = true;
	}

      if (flag[0] and flag[1]) cout << -1 << endl;
      else if (flag[0] and !flag[1]) cout << answer[1] << endl;
      else if (!flag[0] and flag[1]) cout << answer[0] << endl;
      else cout << min(answer[0], answer[1]) << endl;
    }
  

  return 0;
}
