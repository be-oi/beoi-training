#include <bits/stdc++.h>
using namespace std;

int stack_overflow(int depth) {
  int b = depth;
  int a = stack_overflow(depth+1);
  return a;
}

int segfault() {
  vector<int> vec(42);
  return vec[123123123];
}

int fast_pow(int b, int e) {
  if(e == 0)
    return 1;
  int x = fast_pow(b, e/2);
  int result = x*x;
  if(e%2 == 1)
    result *= b;
  return result;
}


int main() {
  string TEXT = R"HELLO(\
Welcome to examplecode.cpp.
Type 1 for stack overflow.
Type 2 for segfault.
Type 3 for fast_pow.
)HELLO";
  cout << TEXT;
  int x;
  while(cout << "(command number) > ", cin >> x) {
    if(x == 1) {
      stack_overflow(0);
    } else if(x == 2) {
      segfault();
    } else if(x == 3) {
      cout << "Enter a and b for a^b." << endl;
      int a, b;
      cin >> a >> b;
      cout << fast_pow(a, b) << endl;
    }
  }
}
