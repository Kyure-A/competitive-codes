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
  int h, w; cin >> h >> w;
  vector<vector<char>> A(h, vector<char>(w));
  
  for (int i = 0; i < h; ++i)
    {
      for (int j = 0; j < w; ++j)
	{
	  cin >> A[i][j];
	}
    }
  
  int q;
  cin >> q;

  while (--q)
    {
      int a, b;
      cin >> a >> b;

      for (int a_index = 0; a_index < a; ++a_index)
	{
	  for (int b_index = 0; b_index < b; ++b_index)
	    {
	      int Ha = h - a;
	      int Wb = w - b;
	      int Ha_index = h - a_index;
	      int Wb_index = w - b_index;

	      // solve
	      swap(A[a_index][b_index], A[a - a_index][b - b_index]);
	      swap(A[Ha_index][b_index], A[Ha - Ha_index][b - b_index]);
	      swap(A[a_index][Wb_index], A[a - a_index][Wb - Wb_index]);
	      swap(A[Ha_index][Wb_index], A[Ha - Ha_index][Wb - Wb_index]);
	    }
	}
      
      
    }

  // output

  for (int i = 0; i < h; ++i)
    {
      for (auto result : A[i])
	{
	  cout << result;
	}
      
      cout << endl;
    }
  

  return 0;
}
