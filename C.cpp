#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll quick_pow(ll x, ll n) {
  ll res = 1;
  while(n) {
    if(n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
ll inv(ll x) {
  return quick_pow(x, mod - 2);
}
int main() {
  ll n;
  while(cin >> n) {
    cout << (n * (n - 1)) % mod * inv(4) % mod << endl;
  }
}
