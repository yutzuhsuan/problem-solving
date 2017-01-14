#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main(void)
{
  int n;
  scanf("%d\n", &n);
  while (n--) {

    map<string, vector<string> > m;
    typedef pair<string, string> P;
    priority_queue<P, vector<P>, greater<P> > pq;

    string s;

    while (getline(cin, s) && s != "") {
      string anagram = s;
      sort(anagram.begin(), anagram.end());
      // cout << trim(s) << endl;
      anagram = trim(anagram);
      if (m.find(anagram) == m.end())
        m.insert(pair<string, vector<string> >(anagram, {s}));
      else {
        for (int i = 0; i < m[anagram].size(); i++) {
          if (m[anagram][i] < s) {
            pq.push(pair<string, string>(m[anagram][i], s));
          } else {
            pq.push(pair<string, string>(s, m[anagram][i]));
          }
        }
          
        m[anagram].push_back(s);

      }
    }
    

    while (!pq.empty()) {
      cout << pq.top().first << " = " << pq.top().second << endl;
      pq.pop();
    }

    if (n)
      puts("");

  }

  return 0;
}

