#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0, m = 0;
  cin >> n >> m;
  unordered_set<string> s;
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    s.insert(str);
  }

  int count = 0;
  vector<string> result;
  for (int i = 0; i < m; i++) {
    cin >> str;
    if (s.find(str) != s.end()) {
      result.push_back(str);
      count++;
    }
  }
  std::sort(result.begin(), result.end());

  cout << count << '\n';
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << '\n';
  }
  return 0;
}