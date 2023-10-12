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
  string answer = "No";
  string nagasa6 = "";
  nagasa6 += s[1];
  nagasa6 += s[2];
  nagasa6 += s[3];
  nagasa6 += s[4];
  nagasa6 += s[5];
  nagasa6 += s[6];
  bool flag1 = false;
  bool flag2 = false;
  bool flag3 = false;
  bool flag4 = false;

  if (s.size() == 8) flag1 = true;

  for (auto i : {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'})
    {
      if (s[0] == i) 
	{
	  flag2 = true;
	}

      if (s[7] == i)
	{
	  flag3 = true;
	}
    }

  for (int i = 100000; i <= 999999; ++i)
    {
      if (to_string(i) == nagasa6) flag4 = true;
    }

  if (flag1 && flag2 && flag3 && flag4) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
