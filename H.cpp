#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e5 + 10;
const ull M = 1e15;
int cnt[maxn];
ull ans[maxn];
ull A, B, n, s0, L;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> A >> B >> L >> n >> s0;
  cnt[s0 / M]++;
  ull t0 = s0;
  for(int i = 1; i < n; i++) {
    s0 = A * s0 + B;
    cnt[s0 / M]++;
  }
  int k = 0;
  for(int i = 0; i < maxn; i++) {
    k = i;
    if(L <= cnt[i]) break;
    L -= cnt[i];
  }
  int m = 0;
  for(int i = 1; i <= n; i++) {
    if(t0 / M == k) ans[++m] = t0;
    t0 = t0 * A + B;
  }
  sort(ans + 1, ans + m + 1);
  cout << ans[L] << endl;
}
