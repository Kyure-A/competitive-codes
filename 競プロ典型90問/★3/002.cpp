/* include */
// #include<bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

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
typedef long long int64;
typedef long double ld;

/* Const */
const double PI = acos(-1.0);
const int64 MOD = 1000000007;
const int64 _MOD = 998244353;


bool validp (string s)
{
  int n = s.size();
  int score = 0;
  
  for (int i = 0; i < n; ++i)
    {
      if (s[i] == '(') score++;
      else if (s[i] == ')') score--;

      if (score < 0) return false;
    }

  if (score != 0) return false;
  else return true;
  
}
  
signed main ()
{
  int n; cin >> n;

  vector<string> paren;
  
  for (int bit = 0; bit < (1 << n); ++bit)
    {
      string s = "";
      
      for (int i = n - 1; i >= 0; --i) // 最上位 bit から見る
	{
	  if (!(bit & (1 << i))) s.push_back('(');
	  else s.push_back(')');
	}

      paren.push_back(s);
      
    }

  for (auto i : paren) if (validp(i)) cout << i << endl;

  return 0;
}
