#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int L, r, R;
double cal(int a, int b, int c) {
  return (1.0 * (a * a + b * b - c * c) / (2 * a * b));
}
double get(double ang, double r) {
  double res = 0;
  res += 2 * pi * r * r * (1 - ang);
  return res;
}
int main() {
  while(cin >> R >> r >> L) {
    double ans = 0;
    if(R < r) swap(R, r);
    if(L >= r + R) {
      ans = 4 * pi * (R * R  + r * r);
    } else if(R - r >= L) {
      ans = 4 * pi * R * R ;
    } else {
      ans = 4 * pi * (R * R + r * r);
      double ang = cal(R, L, r);
      ans -= get(ang, R);
      ang = cal(r, L, R);
      ans -= get(ang, r);
    }
    cout << fixed << setprecision(8) << ans << endl;
  }
}
