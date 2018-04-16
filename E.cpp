#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int maxn = 2010;
const int maxk = 5010;
using ll = long long;
using pii = pair<ll, int>;
ll dis[maxk], b[maxn], n, m;
int main() {
  cin >> n >> m;
  ll M = maxk;
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
    M = min(M, b[i]);
  }
  priority_queue<pii> q;
  memset(dis, 0x3f, sizeof dis);
  dis[0] = 0;
  q.push(mp(0, 0));
  while(!q.empty()) {
    int u = q.top().second;
    ll dd = q.top().first;
    q.pop();
    if(dd > dis[u] || dis[u] > n) continue;
    for(int i = 1; i <= m; i++) {
      int v = (u + b[i]) % M;
      if(dis[v] > dis[u] + b[i]) {
        dis[v] = dis[u] + b[i];
        q.push(mp(-dis[v], v));
      }
    }
  }
  ll ans = 1e16;
  for(int i = 0; i < M; i++) {
    if(dis[i] <= n) {
      ll a = n % M, b = i % M;
      ans = min(ans, min(abs(a - b), M - abs(a - b)));
    } else
      ans = min(ans, dis[i] - n);
  }
  cout << ans << endl;
}
