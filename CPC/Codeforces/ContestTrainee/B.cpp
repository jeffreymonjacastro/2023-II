#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n; 
  cin >> n;

  string v; 
  cin >> v;

  for (int i = 0; i < n - 1; i++){
    if (v[i] == 'R' && v[i + 1] == 'L') {
      cout << 0 << endl;
      return;
    }

    if (v[i] == 'L' && v[i + 1] == 'R') {
      cout << i + 1 << endl;
      return;
    }
  }

  cout << -1 << endl;
}

int main(){
  int t;
  cin>>t;

  while(t--)
    solve();

  return 0;
}