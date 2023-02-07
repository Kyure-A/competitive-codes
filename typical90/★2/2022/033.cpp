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


// 解説AC なんかh,w が二個増えるとLEDが一つ増えるみたいな考えをしていた

signed main ()
{
  int h, w;
  cin >> h >> w;

  if (h == 1 or w == 1) cout << h * w << endl;
  else cout << ((h + 1) / 2) * ((w + 1) / 2) << endl;

  return 0;
}
