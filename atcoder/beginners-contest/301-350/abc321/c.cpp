#include <bits/stdc++.h>
using namespace std;
#define all(container) (container).begin(), (container).end()
#define ctoi(char) int(char) - 48
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
// #define int long long
const double PI = acos(-1.0);
constexpr long long  MOD = 1000000007;
constexpr long long _MOD = 998244353;
using int64 = long long;

signed main ()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int64 k; cin >> k;
  // そもそも 321-like number の最大値は 9876543210 ≈ 9 * 10^10 である

  vector<int64> one = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  vector<int64> two = {10, 20, 30, 40, 50, 60, 70, 80, 90,
		       21, 31, 41, 51, 61, 71, 81, 91,
		       32, 42, 52, 62, 72, 82, 92,
		       43, 53, 63, 73, 83, 93,
		       54, 64, 74, 84, 94,
		       65, 75, 85, 95,
		       76, 86, 96,
		       87, 97,
		       98};

  vector<int64> three;

  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : two)
	{
	  if (x % 10 > i)
	    {
	      three.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> four;

  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : three)
	{
	  if (x % 10 > i)
	    {
	      four.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> five;

  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : four)
	{
	  if (x % 10 > i)
	    {
	      five.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> six;

  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : five)
	{
	  if (x % 10 > i)
	    {
	      six.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> seven;

  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : six)
	{
	  if (x % 10 > i)
	    {
	      seven.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> eight;

  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : seven)
	{
	  if (x % 10 > i)
	    {
	      eight.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> nine;
  
  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : eight)
	{
	  if (x % 10 > i)
	    {
	      nine.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> ten;

  for (int64 i = 0; i <= 9; ++i)
    {
      for (int64 x : nine)
	{
	  if (x % 10 > i)
	    {
	      ten.push_back(x * 10 + i);
	    }
	}
    }

  vector<int64> result;
  result.insert(result.end(), all(one));
  result.insert(result.end(), all(two));
  result.insert(result.end(), all(three));
  result.insert(result.end(), all(four));
  result.insert(result.end(), all(five));
  result.insert(result.end(), all(six));
  result.insert(result.end(), all(seven));
  result.insert(result.end(), all(eight));
  result.insert(result.end(), all(nine));
  result.insert(result.end(), all(ten));

  sort(all(result));
  
  cout << result[k - 1] << endl;
  
  return 0;
}
