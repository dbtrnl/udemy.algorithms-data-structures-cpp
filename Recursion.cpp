#include <iostream>

using namespace std;

void tail(int n) {
  if (n == 0) return;
  cout << "Tail function called with n = " << n << endl;
  tail(n-1);
}

void head(int n) {
  if (n == 0) return;
  head(n-1);
  cout << "Head function called with n = " << n << endl;
}

int main() {
  tail(5);
  head(5);
  return 0;
}