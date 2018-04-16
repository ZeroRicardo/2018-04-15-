#include <bits/stdc++.h>
using namespace std;
char c[55] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
string s[55] = {
"Alfa",  "Bravo",  "Charlie",  "Delta",  "Echo",  "Foxtrot",  "Golf",
"Hotel",  "India",  "Juliett",  "Kilo",  "Lima",  "Mike",  "November",
 "Oscar",  "Papa",  "Quebec",  "Romeo",  "Sierra",  "Tango",  "Uniform",
  "Victor",  "Whiskey",  "Xray",  "Yankee",  "Zulu",
  "Zero",  "One",  "Two",  "Three",  "Four",  "Five",  "Six",  "Seven",  "Eight",  "Nine",
};
char op[100010];
int main() {
  while(cin >> op) {
    cout << "CQCQCQ this is " << op << " ";
    for(int i = 0; op[i]; i++) {
      char t = op[i];
      if('a' <= t && t <= 'z')  t += 'A' - 'a';
      for(int j = 0; ;j++)
        if(t == c[j]) {
          cout << s[j] << " ";
          break;
        }
    }
    cout << op << endl;
  }
}
