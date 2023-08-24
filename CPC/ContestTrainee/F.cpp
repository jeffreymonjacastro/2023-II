#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x, y;
  long long int min = 1e9;
  cin >> n;
  x = 1; y = n - 1;

  for (int i = 1; i <= n/2; i++){
    string a, b;
    long long int sum = 0;
    a = to_string(x);
    b = to_string(y);

    for (int j = 0; j < a.size(); j++)
      sum += a[j] - '0';

    for (int j = 0; j < b.size(); j++)
      sum += b[j] - '0';
    
    if (sum < min)
      min = sum;

    x++; y--;
  }
  
  cout << min << endl;

  return 0;
}