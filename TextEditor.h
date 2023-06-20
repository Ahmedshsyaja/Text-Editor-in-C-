#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#pragma once
void gotoRowCol(int rpos, int cpos);
struct node {
	string data;
	node* next;
};

class parent {
	node* head = nullptr;
	node* curr = nullptr;
public:
	parent();
	bool isEmpty();
	void create_node(string value);
	void print();
	node* R_Head() {
		return this->head;
	}
	void deleteList(node** head_ref);
};

class TrieNode {
public:
	char data;
	TrieNode** children;
	bool isTerminal;
	TrieNode(char data);
};

class Trie {
	TrieNode* root;
public:
	int count;
	Trie();
	bool insertWord(TrieNode* root, string word);
	void insertWord(string word);
	void complete(TrieNode* root, string word, string output, bool& possible, string& key);
	void autoComplete(string& key, bool& possible);
};

class Line {
private:
	friend class TextEditor;
	friend class Document;
	int Size;
	char* Cs;
public:
	Line();
	void Delete(int& cc);
	void check();
	void HUFFMAN();
	Line(const Line& AL);
	void Insert(int& a, int& count);
	void InsertCharAt(int i, char ch);
};

class Document {
private:
	friend class TextEditor;
	int NOLs;   //number of lines
	Line* Ls; //lines
	string DName;   //document name
public:
	Document(string fname);
	void Load(string fname);
	void Insert();
	void InsertACharacter(int li, int& ci, int ch);
	void PrintDocument();
};

class TextEditor {
private:
	int cr = 0, cc = 0;
	Document* ADocument;
public:
	// addition
	void check(); //addition
	TextEditor(string dname);
	void Editing();
	void InsertACharacter(int ch);
	~TextEditor();
};