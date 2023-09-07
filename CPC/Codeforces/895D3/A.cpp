#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
typedef long double lld;

const int MAX = INT32_MAX;
const int MIN = INT32_MIN;

void solve(){
  int a, b, c, count = 0;
  cin>>a>>b>>c;

  int resta = abs(a - b);
  
  if (a == b) {
    cout << "0" << endl;
  } else if (c >= resta) {
      cout << "1" << endl;
  } else {
    int residuo;
    if (resta % c == 0) {
      residuo = 0;
    } else {
      residuo = 1;
    }
    cout << (resta / c - 1) + residuo << endl;
  }
}

int main(){
  cpu();
  int t=1; 
  cin>>t;
  
  while(t--)
    solve();
}
