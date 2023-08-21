#include <bits/stdc++.h>

using namespace std;

string sin_cero(string& s){
  string temp = "";
  for (int i = 0; i < s.size(); i++){
    if (s[i] != '0')
      temp += s[i];
  }
  return temp;
}

int main(){
  long long int a, b;
  cin >> a >> b;
  string c = to_string(a);
  string d = to_string(b);
  string sum = to_string(a + b);

  c = sin_cero(c);
  d = sin_cero(d);
  sum = sin_cero(sum);

  if (stoi(c) + stoi(d) == stoi(sum))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}