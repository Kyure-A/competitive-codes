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

signed itrToIndex (vector<int> vec, signed wanted_value)
{
  auto itr = lower_bound(vec.begin(), vec.end(), wanted_value);
  if (itr == vec.end()) return -1;
  else return distance(vec.begin(), itr);
}

signed main ()
{
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n); rep(i, n) cin >> a[i] >> b[i];
  vector<int> a_greater, b_greater;
  a_greater = a; sort(all(a_greater), greater<int>());
  b_greater = b; sort(all(b_greater), greater<int>());
  
  vector<bool> selected(n, false);

  long long answer = 0;

  for (int i = 0; i < n; ++i)
    {
      if (a_greater[i] > b_greater[i])
	{
	  if (k - 2 >= 0 and !selected[itrToIndex(a, a_greater[i])])
	    {
	      answer += a_greater[i];
	      k -= 2;
	      selected[itrToIndex(a, a_greater[i])] = true;
	    }

	  if (k - 1 >= 0 and !selected[itrToIndex(b, b_greater[i])])
	    {
	      answer += b_greater[i];
	      k -= 1;
	      selected[itrToIndex(b, b_greater[i])] = true;
	    }
	}

      else
	{
	  if (k - 1 >= 0 and !selected[itrToIndex(b, b_greater[i])])
	    {
	      answer += b_greater[i];
	      k -= 1;
	      selected[itrToIndex(b, b_greater[i])] = true;
	    }
	  
	  if (k - 2 >= 0 and !selected[itrToIndex(a, a_greater[i])])
	    {
	      answer += a_greater[i];
	      k -= 2;
	      selected[itrToIndex(a, a_greater[i])] = true;
	    }
	}
    }

  cout << answer << endl;
  
  return 0;
}
