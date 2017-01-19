#include <stdio.h>
#include <deque>
#include <queue>
#include <set>
#include <string.h>
using namespace std;

struct snapshot {
	int val[60];
	snapshot() {
		memset(val, 0, sizeof(val));
	}
	bool operator<(const snapshot &n) const {
		return memcmp(val, n.val, sizeof(snapshot)) < 0;
	}
	
};
queue<int> hand;
deque<int> card[7];
set<snapshot> check_loop;
void init()
{
	while(!hand.empty())
		hand.pop();
	for(int i = 0; i < 7; i++)
		card[i].clear();
	return ;
}

int main(void)
{
	int temp;
	int flag = 0;
	int is_end, cnt;
	int word_cnt;
	
	while(1) {
		init();
		flag = 0;
		for(int i = 0; i < 52; i++) {
			scanf(" %d", &temp);
			if(!temp) {
				flag = 1;
				break;
			}
			hand.push(temp);	
		}
		if(flag)
			break;
		for(int i = 0; i < 14; i++) {
			card[i%7].push_back(hand.front());
			hand.pop();
		}
		cnt = 14;
		while(1) {
			for(int i = 0; i < 7; i++) {
				if(card[i].size() == 0)
					continue;
				card[i].push_back(hand.front());
				hand.pop();
				cnt++;
				while(card[i].size() >= 3) {
					if(!((card[i][0] + card[i][1] + card[i][card[i].size()-1])%10)) {
						hand.push(card[i][0]);
						hand.push(card[i][1]);
						hand.push(card[i][card[i].size()-1]);
						card[i].pop_front();
						card[i].pop_front();
						card[i].pop_back();
					}
					else if(!((card[i][0] + card[i][card[i].size()-2] + card[i][card[i].size()-1])%10)) {
						hand.push(card[i][0]);
						hand.push(card[i][card[i].size()-2]);
						hand.push(card[i][card[i].size()-1]);
						card[i].pop_front();
						card[i].pop_back();
						card[i].pop_back();
					}
					else if(!((card[i][card[i].size()-3] + card[i][card[i].size()-2] + card[i][card[i].size()-1])%10)) {
						hand.push(card[i][card[i].size()-3]);
						hand.push(card[i][card[i].size()-2]);
						hand.push(card[i][card[i].size()-1]);
						card[i].pop_back();
						card[i].pop_back();
						card[i].pop_back();
					}
					else
						break;
				}
				if(hand.size() == 0) {
					printf("Loss: %d\n", cnt);
					flag = 1;
					break;
				}
				if(hand.size() == 52) {
					printf("Win : %d\n", cnt);
					flag = 1;
					break;
				}

				check_loop;
				word_cnt = 0;
				snapshot s;
				queue<int> tmp = hand;
				for(int j = 0; j < 7; j++) {
					for(int k = 0; k < card[j].size(); k++)
						s.val[word_cnt++] = card[j][k];
					s.val[word_cnt++] = -1;
				}
				while(!tmp.empty()) {
					s.val[word_cnt++] = tmp.front();
					tmp.pop();
				}
				if(check_loop.find(s) != check_loop.end()) {
					printf("Draw: %d\n", cnt);
					flag = 1;
					break;
				}
				check_loop.insert(s);
			}
			if(flag)
				break;
		}
		
	}
	return 0;
}