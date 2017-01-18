#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

// 這題明明 uDebug 上面的測資都過了還是 WA QQ
// 最後只好參考 morris 大神惹

void output(set<string> bloods) {
  if (!bloods.size()) {
    cout << "IMPOSSIBLE";
    return ;
  }
  if (bloods.size() > 1)
    cout << "{";
  for (set<string>::iterator it = bloods.begin(); it != bloods.end(); it++) {
    if (it != bloods.begin())
      cout << ", ";
    cout << *it;
  }
  if (bloods.size() > 1)
    cout << "}";
}

string convertShort(string s) {
  if (s == "OO") return "O";
  else if (s == "AO") return "A";
  else if (s == "OA") return "A";
  else if (s == "AA") return "A";
  else if (s == "BO") return "B";
  else if (s == "OB") return "B";
  else if (s == "BB") return "B";
  else if (s == "AB") return "AB";
  else if (s == "BA") return "AB";
}
string convertLong(string s) {
  if (s == "AB") return "AB";
  else if (s == "O") return "OO";
  else if (s == "A") return "AO";
  else if (s == "B") return "BO";
}

set<string> child(string p1, string p2) {

  set<string> ret;
  string rh;
  if (p1.substr(p1.size()-1, 1) == "-" && p2.substr(p2.size()-1, 1) == "-") {
    rh = "-";
  } else {
    rh = "-+";
  }

  p1 = convertLong(p1.substr(0, p1.size()-1));
  p2 = convertLong(p2.substr(0, p2.size()-1));

  for (int i = 0; i < p1.size(); i++) {
    for (int j = 0; j < p2.size(); j++) {
      string tmp = convertShort(p1.substr(i, 1)+p2.substr(j, 1));
      for (int k = 0; k < rh.size(); k++) {
        ret.insert(tmp+rh.substr(k, 1));
      }
    }
  }

  return ret;
}

set<string> parent(string a, string b) {
  
  set<string> ret;
  string bloods[] = {"A", "B", "AB", "O"  };

  for (int i = 0; i < 4; i++) {
    set<string> tmp1 = child(a, bloods[i]+"+");
    // cout << a << " " << bloods[i]+"+" << endl;
    if (tmp1.find(b) != tmp1.end())
      ret.insert(bloods[i]+"+");
    set<string> tmp2 = child(a, bloods[i]+"-");
    if (tmp2.find(b) != tmp2.end())
      ret.insert(bloods[i]+"-");
  }

  return ret;
}

int main(void)
{
  string p1, p2, c;
  int cnt = 1;

  while (cin >> p1 >> p2 >> c) {
    if (p1 == "E")
      break;
    // cout << p1 << " " << p2 << " " << c << endl;

    if (c == "?") {
      printf("Case %d:", cnt++);
      cout << " " << p1 << " " << p2 << " ";
      set<string> bloods = child(p1, p2);
      output(bloods);
      puts("");
    } else if (p1 == "?") {

      printf("Case %d: ", cnt++);
      set<string> bloods = parent(p2, c);
      output(bloods);
      cout << " " << p2 << " " << c;
      puts("");
    } else if (p2 == "?") {
      
      printf("Case %d:", cnt++);
      cout << " " << p1 << " ";
      set<string> bloods = parent(p1, c);
      output(bloods);
      cout << " " << c;
      puts("");
    }
  }

  return 0;
}

