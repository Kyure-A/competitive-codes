#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/modint>
// using namespace atcoder;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;

int findMaxFreeDays(int N, int D, const vector<string>& schedules)
{
  int maxFreeDays = 0;

  for (int day = 0; day < D; ++day)
    {
      bool allFree = true;
      for (int person = 0; person < N; ++person)
	{
	  if (schedules[person][day] == 'x')
	    {
	      allFree = false;
	      break;
	    }
	}
      
      if (allFree)
	{
	  int consecutiveDays = 1;
	  while (day + consecutiveDays < D)
	    {
	      bool allFreeNextDay = true;
	      for (int person = 0; person < N; ++person)
		{
		  if (schedules[person][day + consecutiveDays] == 'x')
		    {
		      allFreeNextDay = false;
		      break;
		    }
		}
	      
	      if (allFreeNextDay) consecutiveDays++;
	      else break;
	    }
	  
	  maxFreeDays = max(maxFreeDays, consecutiveDays);
      }
  }

  return maxFreeDays;
}

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, d; cin >> n >> d;
  vector<string> s(n); rep(i, n) cin >> s[i];

  int maxFreeDays = findMaxFreeDays(n, d, s);

  cout << maxFreeDays << endl;
  
  return 0;
}
