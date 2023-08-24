#include <bits/stdc++.h>

using namespace std;


int main(){
  int t, x = 1;
  cin>>t;

  vector<int> v(t);
  vector<int> res;

  for (int i = 0; i < t; i++){
    cin>>v[i];

    if (v[i] == x) {
      res.push_back(v[i]);
      x++;
    }
  }

  if (res.size() == 0) 
    cout << -1 << endl;
  else
    cout << t - res.size() << endl;
  
  return 0;
}