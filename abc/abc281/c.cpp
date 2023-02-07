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
  long long n, t;
  cin >> n >> t;
  vector<long long> a(n + 1);
  a[0] = -1;
  
  for (int i = 1; i <= n; ++i)
    {
      cin >> a[i]; 
    }

  vector<long long> sum(n + 1);
  vector<long long> reversed_sum(n + 1);
  sum[0] = 0;
  sum[1] = a[1];
  for (int i = 2; i <= n; ++i)
    {
      sum[i] = sum[i - 1] + a[i];
    }

  reversed_sum[n] = a[n];
  reversed_sum[n - 1] = reversed_sum[n] + a[n - 1];
  for (int i = n - 2; i >= 1; --i)
    {
      reversed_sum[i] = reversed_sum[i + 1] + a[i]; 
    }
  reversed_sum[0] = reversed_sum[1];

  // solve

  int music_number = -1;
  int music_time = -1;

  int remainder = t % sum[n];
  
  if (t > sum[n])
    {
      for (int i = 1; i <= n; ++i)
	{
	  if (sum[i - 1] < remainder && remainder <= sum[i])
	    {
	      music_number = i;
	      music_time = remainder - sum[i - 1];

	      break;
	    }
	}
    }

  else if (t == sum[n])
    {
      music_number = 1;
      music_time = 0;
    }

  else if (t < sum[n])
    {
      int remainder = sum[n] % t;
      for (int i = n; i >= 1; --i)
	{
	  if (reversed_sum[i] > remainder)
	    {
	      music_number = i;
	      music_time = reversed_sum[i] - remainder;
	      break;
	    }
	  else remainder - reversed_sum[i];
	}
    }

  cout << music_number << " " << music_time << endl;

  return 0;
}
