#include <bits/stdc++.h>

using namespace std;

#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr)
typedef long long ll;
typedef long double lld;

#define rep(i, a, b) for (ll i=a; i<b; i++);
#define rev(i, a, b) for (ll i=a; i>=b; i--);

const int MAX = INT32_MAX;
const int MIN = INT32_MIN;

void solve(){
  ll n;
  cin>>n;

  vector<ll> b(n);

  for(int i = 0; i < n; i++){
    cin>>b[i];
  }

  vector<ll> a;
  a.push_back(b[0]);

  for(int i = 1; i < n; i++){
    if(b[i] >= b[i-1])
      a.push_back(b[i]);
    else { 
      a.push_back(1);
      a.push_back(b[i]);
    }
  }

  cout<<a.size()<<endl;
  for(int i = 0; i < a.size(); i++)
    cout<<a[i]<<" ";

  cout<<endl;
}

int main(){
  cpu();
  int t=1; 
  cin>>t;
  
  while(t--)
    solve();
}
