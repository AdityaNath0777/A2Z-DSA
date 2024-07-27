#include <bits/stdc++.h>
using namespace std;

int fib_rec(int n){
  if (n==0) return 0;
  if (n==1) return 1;
  return fib_rec(n-1) + fib_rec(n-2);
}

int fib_loop(int n){
  if (n==0) return 0;
  if (n==1) return 1;
  int f0 = 0;
  int f1 = 1;
  int fn = 1;

  for (int i=2; i<=n; ++i){
    fn = f1 + f0;
    f0 = f1;
    f1 = fn;
  }
  return fn;
}

int main(int argc, char* argv[]){
  int n;
  cin >> n;

  cout << fib_rec(n) << "\n"; 
  cout << fib_loop(n) << endl; 
return 0;
}