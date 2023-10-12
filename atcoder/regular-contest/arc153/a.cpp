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
  int n;
  cin >> n;

  vector<string> zorome = {"00", "11", "22", "33", "44", "55", "66", "77", "88", "99"};
  vector<string> itimoji = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

  vector<long> good_number;

  for (int i = 1; i <= 9; ++i)
    {
      for (int j = 0; j <= 9; ++j)
	{
	  for (int k = 0; k <= 9; ++k)
	    {
	      for (int l = 0; l <= 9; ++l)
		{
		  for (int m = 0; m <= 9; ++m)
		    {
		      for (int o = 0; o <= 9; ++o)
			{
			  string number = zorome[i] + itimoji[j] + itimoji[k] + zorome[l] + itimoji[m] + itimoji[o] + itimoji[m];
			  long num_to_str = stol(number);
			  good_number.push_back(num_to_str);
			}
		    }
		}
	    }
	}
      
    }

  sort(good_number.begin(), good_number.end());

  cout << good_number[n + 1] << endl;
  return 0;
}
