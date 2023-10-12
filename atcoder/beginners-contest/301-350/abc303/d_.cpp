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

  long long x, y, z; cin >> x >> y >> z;
  string s; cin >> s;
  vector<pair<char, int>> encoded_string = encode(s);

  long long time = 0;

  bool isCapsLocked = false;
  
  for (int i = 0; i < (int) encoded_string.size(); ++i)
    {
      if (encoded_string[i].first == 'a')
	{
	  if (!isCapsLocked)
	    {
	      // CapsLock が OFF なら 普通に a を押す (x) 方が早いか，CapsLock を押して Shift + a を押す (y + z) 方が早いか
		if (encoded_string[i].second * y + z < encoded_string[i].second * x)
		{
		  isCapsLocked = !isCapsLocked;
		  time += encoded_string[i].second * y + z;
		}

	      else if (encoded_string[i].second * y + z > encoded_string[i].second * x)
		{
		  time += encoded_string[i].second * x;
		}
	    }

	  else
	    {
	      // CapsLock が ON なら 普通に A を押す (x) 方が早いか，CapsLock を押して Shift + A を押す (y + z) 方が早いか
	      if (encoded_string[i].second * x < encoded_string[i].second * y + z)
		{
		  isCapsLocked = !isCapsLocked;
		  time += encoded_string[i].second * x;
		}

	      else if (encoded_string[i].second * x > encoded_string[i].second * y + z)
		{
		  time += encoded_string[i].second * y + z;
		}
	    }
	}

      else
	{
	  if (!isCapsLocked)
	    {
	      // CapsLock が OFF なら 普通に A を押す (x) 方が早いか，CapsLock を押して Shift + a を押す方 (y + z) が早いか
	      if (encoded_string[i].second * x < encoded_string[i].second * y + z)
		{
		  isCapsLocked = !isCapsLocked;
		  time += encoded_string[i].second * x;
		}

	      else if (encoded_string[i].second * x > encoded_string[i].second * y + z)
		{
		  time += encoded_string[i].second * y + z;
		} 
	    }
	  
	  else
	    {
	      // CapsLock が ON なら 普通に a を押す方 (x) が早いか，CapsLock を押して Shift + A を押す方が (y + z) 早いか
	      if (encoded_string[i].second * x < encoded_string[i].second * y + z)
		{
		  isCapsLocked = !isCapsLocked;
		  time += encoded_string[i].second * y + z;
		}

	      else if (encoded_string[i].second * x > encoded_string[i].second * y + z)
		{
		  time += encoded_string[i].second * x;
		}
	    }
	}
    }
  
  cout << time << endl;

  return 0;
}
