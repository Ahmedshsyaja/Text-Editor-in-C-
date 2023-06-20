#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <bitset>
#include <unordered_map>
using namespace std;
class NODE;
void To_bin(string s);
void binarY_convertor(string s);
static string str;
static int extra = 0;
struct compare;
int hcount = 0;
void encode(NODE* root, string str, unordered_map<char, string>& compressed_code);
string convertToString(char* a, int size);
void H_Tree(string text);
//NODE Structure
class NODE {
public:
	char ch;
	int FrequencY;
	NODE* left, * right;
	NODE(char ch, int FrequencY, NODE* left, NODE* right) {
		this->ch = ch;
		this->FrequencY = FrequencY;
		this->left = left;
		this->right = right;
	}
};
struct compare {
	bool operator()(NODE* l, NODE* r) {
		return (l->FrequencY > r->FrequencY);
	}
};

void encode(NODE* root, string str, unordered_map<char, string>& compressed_code) {
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		compressed_code[root->ch] = str;
	}
	encode(root->left, str + "0", compressed_code);
	encode(root->right, str + "1", compressed_code);
}
string convertToString(char* a, int size) {
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}
void decode(NODE* root, int& index, string str) {
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right) {
		cout << root->ch;
		return;
	}
	index++;
	if (str[index] == '0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}
void H_Tree(string text) {
	hcount++;
	unordered_map <char, int> FrequencY;
	for (char ch : text) {
		FrequencY[ch]++;
	}
	priority_queue <NODE*, vector <NODE*>, compare> minheap;
	for (auto pair : FrequencY) {
		minheap.push(new NODE(pair.first, pair.second, nullptr, nullptr));
	}
	while (minheap.size() != 1) {
		NODE* left = minheap.top();
		minheap.pop();
		NODE* right = minheap.top();
		minheap.pop();
		int sum = left->FrequencY + right->FrequencY;
		minheap.push(new NODE('\0', sum, left, right));
	}
	NODE* root = minheap.top();
	unordered_map<char, string> compressed_code;
	encode(root, "", compressed_code);
	string str = "";
	for (char ch : text) {
		str += compressed_code[ch];
	}
	cout << "\nENCODED DATA IS : " << str << '\n';
	ofstream fout;
	fout.open("encoding.txt",ios::app);
	fout << str<<endl;
	fout.close();
	int index = -1;
	cout << "\nDECODED DATA IS : ";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
	To_bin(str);
}
void binarY_convertor(string s) {
	int x = 0;
	int sum = 0;
	for (int i = 0, j = 8; i < 8; i++, j--) {
		x = x + (int)s[i];
		x = x - 48;
		if (i != 7) {
			x = x << 1;
		}
	}
	str.push_back((char)x);
}
void To_bin(string s) {
	int count = 0;
	string temp;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		count++;
		if (count == 8) {
			temp = s.substr(0, 8);
			binarY_convertor(temp);
			s.erase(0, 8);
			count = 0;
		}
	}
	cout << endl;
	if (s.size() < 8 && s.size() > 0) {
		for (int i = s.size(); i < 8; i++) {
			s.push_back('0');
			extra++;
		}
		binarY_convertor(s);
	}
}
