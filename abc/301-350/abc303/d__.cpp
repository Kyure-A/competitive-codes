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
	      long long output_a_1 = x * encoded_string[i].second;
	      long long output_a_2 = y * encoded_string[i].second + z;

	      long long output_A_1 = y * encoded_string[i].second;
	      long long output_A_2 = x * encoded_string[i].second + z;
	      
	      if (output_a_2 < output_a_1)
		{
		  isCapsLocked = !isCapsLocked;
		  time += output_a_2;
		}

	      else if (output_a_2 > output_a_1)
		{
		  time += output_a_1;
		}
	    }

	  else if (isCapsLocked)
	    {
	      long long output_A_1 = x * encoded_string[i].second;
	      long long output_A_2 = y * encoded_string[i].second + z;

	      long long output_a_1 = y * encoded_string[i].second;
	      long long output_a_2 = x * encoded_string[i].second + z;
	      
	      if (output_A_2 < output_A_1)
		{
		  isCapsLocked = !isCapsLocked;
		  time += output_A_2;
		}

	      else if (output_A_1 < output_A_2)
		{
		  time += output_A_1;
		}
	    }
	}

      else if (encoded_string[i].first == 'A')
	{
	  if (!isCapsLocked)
	    {
	      long long output_a_1 = x * encoded_string[i].second;
	      long long output_a_2 = y * encoded_string[i].second + z;

	      long long output_A_1 = y * encoded_string[i].second;
	      long long output_A_2 = x * encoded_string[i].second + z;
	      
	      if (output_a_2 < output_a_1)
		{
		  isCapsLocked = !isCapsLocked;
		  time += output_a_2;
		}

	      else if (output_a_1 < output_a_2)
		{
		  time += output_a_1;
		} 
	    }
	  
	  else if (isCapsLocked) 
	    {
	      long long output_A_1 = x * encoded_string[i].second;
	      long long output_A_2 = y * encoded_string[i].second + z;

	      long long output_a_1 = y * encoded_string[i].second;
	      long long output_a_2 = x * encoded_string[i].second + z;
	      
	      if (output_A_2 < output_A_1)
		{
		  isCapsLocked = !isCapsLocked;
		  time += output_A_2;
		}

	      else if (output_A_1 < output_A_2)
		{
		  time += output_A_1;
		}
	    }
	}
    }
  
  cout << time << endl;

  return 0;
}
