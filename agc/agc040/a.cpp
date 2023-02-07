/* include */
#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all> using namespace atcoder;

/* Macro */
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define per(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define per3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))

/* Type */
// #define int long long
#define cauto const auto&
typedef long long i64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const long long  MOD = 1000000007;
const long long _MOD = 998244353;


signed main ()
{
  string s;
  cin >> s;
  
  i64 sum = 0;
  int count = 0;
  char previous = s[0];
  int previous_num = 0;
  
  for (int i = 0; i < (int)s.length(); ++i)
    {
      if (previous == s[i]) count++;

      else if (previous /= s[i])
	{
	  if (previous == '<')
	    {
	      if (i == 1)
		{
		  previous_num = 0;
		  previous = '>';
		}
	      
	      else
		{
		  if (previous_num == 0)
		    {
		      sum += (count * (count + 1)) / 2;
		      previous_num = count;
		      previous = '>';
		    }
		  
		  else
		    {
		      count--;
		      sum += (count * (count + 1)) / 2;
		      previous_num = count;
		      previous = '>';
		    }
		}

	      count = 1;
	    }

	  else if (previous == '>')
	    {
	      if (previous_num == 0)
		{
		  sum += (count * (count + 1)) / 2;
		  previous_num = count;
		  previous = '<';
		}
		  
	      else
		{
		  count--;
		  sum += (count * (count + 1)) / 2;
		  previous_num = count;
		  previous = '<';
		}
	      
	      count = 1;
	    }
	    
	}
    }

  cout << sum << endl;

  return 0;
}
