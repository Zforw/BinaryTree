#include "BinaryTree.h"
#include <time.h>
using namespace std;
bool CheckDuplicate(const string&, const string&);
int main () {
	while(true) {

		string p, mid;
		int choice;
		cout << "输入0: 前序 + 中序, 输入1: 后序 + 中序" << endl;
		cin >> choice;
		//string pre = "ABDFGCEH", mid = "BFDGACEH", post = "FGDBHECA";
		//string pre = "GDAFEMHZ", mid = "ADEFGHMZ", post = "AEFDHZMG";
		//string pre = "ABCDEFGH", mid = "CEDFBAGH", post = "EFDCBHGA";
		//string pre = "ABDHIEJKCFLMGNO", mid = "HDIBJEKALFMCNGO", post = "HIDJKEBLMFNOGCA";
		if(choice != 0 && choice != 1) {
			cout << "输入有误!" << endl;
			continue;
		}
		if(choice == 0) cout << "输入前序:" << endl;
		else cout << "输入后序:" << endl;
		cin >> p;
		cout << "输入中序:" << endl;
		cin >> mid;
		if (! CheckDuplicate (p, mid)) {
			cout << "输入有误!" << endl;
			continue;
		}
		BinaryTree<char> bt;
		time_t st = time (NULL);
		if (bt.BuildTree (choice, p, mid)) {
			time_t ed = time (NULL);
			cout << ed - st << " s";
			break;
		} else {
			cout << "输入有误!" << endl;
		}
	}
	return 0;
}
bool CheckDuplicate(const string &s, const string &m) {
	if(s.length() != m.length()) return false;
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	char c = (s[0] >= 'a')?'a':'A';
	for(char i : s) {
		if(cnt[i - c] == 1) {
			return false;
		} else {
			cnt[i - c]++;
		}
	}
	for(char i : m) {
		if(cnt[i - c] == 1) {
			cnt[i - c]++;
		} else {
			return false;
		}
	}
	return true;
}
