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
  int n,m,k;
  cin>>n>>m;

  k = 0;

  char carpet[n][m];
  vector<char> name = {'v','i','k','a'};
  vector<int> flag(4);
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>carpet[i][j];
    }
  }

  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      if (carpet[j][i] == name[k]){
        flag[k] = 1;
        k++;
        break;
      }
    }
  }
  
  if(flag[0] && flag[1] && flag[2] && flag[3]){
    cout<<"YES"<<endl;
  } else{
    cout<<"NO"<<endl;
  }
}

int main(){
  cpu();
  int t=1; 
  cin>>t;
  
  while(t--)
    solve();
}
