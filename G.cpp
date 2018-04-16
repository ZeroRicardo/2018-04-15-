#include <bits/stdc++.h>
using namespace std;
int fvck[5][12];
int rnk[32];
int winner[32], m;
void get() {
  for(int i = 1; i <= 25; i++) {
    bool f = 1;
    for(int j = 1; j <= 4; j++)
      if(winner[j] == i)  f = 0;
    if(f) {
      winner[++m] = i;
      break;
    }
  }
}
int main() {
  for(int i = 1; i <= 25; i++)
    winner[i] = i;
  for(int i = 1; i <= 25; i += 5) {
    for(int j = i; j <= i + 4; j++)
      cout << j << " ";
    cout << endl;
    fflush(stdout);
    for(int k = 1; k <= 5; k++) {
      int t;  cin >> t;
      if(t <= 2)  fvck[t][(i + 4) / 5] = i + k - 1;
    }
  }
  for(int i = 1; i <= 5; i++)
    cout << fvck[1][i] << " ";
  cout << endl;
  fflush(stdout);
  m = 0;
  for(int i = 1; i <= 5; i++) {
    int t; cin >> t;
    if(t <= 2) {
      winner[++m] = fvck[1][i];
      winner[++m] = fvck[2][i];
    }
  }
  get();
  for(int i = 1; i <= 5; i++)
    cout << winner[i] << " ";
  cout << endl;
  fflush(stdout);
  for(int i = 1; i <= 5; i++) {
    int t; cin >> t;
    rnk[t] = winner[i];
  }
  cout << rnk[1] << " " << rnk[2] << " 0 0 0" << endl; 
}
