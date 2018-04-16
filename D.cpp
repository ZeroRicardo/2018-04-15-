#include <cstdio>
#include <cstring>
using namespace std;
unsigned int sum[10000000];
int t = 0;
int main() {
  int n;
  unsigned int x;
  char s[20];
  scanf("%d", &n);
  for(int i = 0; i< n; i++) {
    scanf("%s%u%*c", s, &x);
    if(strcmp(s, "commit") == 0) {
        sum[++t] = sum[t-1] ^ x;
        printf("%u\n", sum[t]);
    }
    else if (strcmp(s, "checkout") == 0){
      sum[++t] = sum[x];
      printf("%u\n", sum[t]);
    }
  }
}
