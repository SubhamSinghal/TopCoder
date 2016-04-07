#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int((x).size()))
#define bit(x) (1 << (x))
#define cnt1(x) (__builtin_popcount(x))

template<class T>
inline void chkmax(T& x, T y) {
  if (x < y) x = y;
}

template<class T>
inline void chkmin(T& x, T y) {
  if (y < x) x = y;
}

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define Problem MutaliskEasy

const int MX = 65;
const int INF = 100000000;
int dp[MX][MX][MX];

int calc(int x, int y, int z) {
  if (x < 0) return calc(0, y, z);
  if (y < 0) return calc(x, 0, z);
  if (z < 0) return calc(x, y, 0);
  int& rlt = dp[x][y][z];
  if (rlt != -1) return rlt;
  if (!x && !y && !z) return rlt = 0;
  rlt = INF;
  chkmin(rlt, calc(x - 1, y - 3, z - 9));
  chkmin(rlt, calc(x - 1, y - 9, z - 3));
  chkmin(rlt, calc(x - 3, y - 1, z - 9));
  chkmin(rlt, calc(x - 3, y - 9, z - 1));
  chkmin(rlt, calc(x - 9, y - 1, z - 3));
  chkmin(rlt, calc(x - 9, y - 3, z - 1));
  rlt++;
  return rlt;
}

class Problem {
  public:
  int minimalAttacks(VI x) {
    int a, b, rlt;

    if (sz(x) == 1) rlt = (x[0] - 1) / 9 + 1;
    else if (sz(x) == 2) {
      rlt = INF;
      for (a = 0; a <= 20; a++) {
        for (b = 0; b <= 20; b++) {
          if (a * 9 + b * 3 >= x[0] && a * 3 + b * 9 >= x[1]) chkmin(rlt, a + b);
        }
      }
    }
    else {
      memset(dp, -1, sizeof dp);
      rlt = calc(x[0], x[1], x[2]);
    }
    return rlt;
  }
};
//
int main() {
 Problem pro;
 VI x;
   x.pb(60);
   x.pb(60);
   x.pb(60);
 cout << pro.minimalAttacks(x) << endl;
 return 0;
}
//}
