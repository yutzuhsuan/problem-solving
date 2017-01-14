#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(void)
{
  string s;
  map<string, string> m;
  map<string, string>::iterator i;

  while (cin >> s && s != "#") {

    string lowercase = s;
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);

    sort(lowercase.begin(), lowercase.end());


    i = m.find(lowercase);

    if (i != m.end()) {
      i->second = "#"; 
    } else {
      m.insert(pair<string, string>(lowercase, s));
    }

  }

  priority_queue<string, vector<string>, greater<string> > pq;

  for (i = m.begin(); i != m.end(); i++) {
    if (i->second != "#")
      pq.push(i->second);
  }

  while (!pq.empty()) {
    cout << pq.top()  << endl;
    pq.pop();
  }

  return 0;
}

