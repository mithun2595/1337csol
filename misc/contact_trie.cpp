#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#include <string>

using namespace std;

class TrieNode {
    map<char, TrieNode*> children;
    int size;

    public:
    void addChildIfAbsent(char ch) {
        if(children.find(ch) == children.end()) {
            children[ch]=new TrieNode();
        }
    }
    TrieNode* getChild(char ch) {
        return children[ch];
    }

    void incrSize(int n) {
        size += n;
    }

    int getSize() {
        return size;
    }
};
class Trie {
    TrieNode* root = new TrieNode();
    public:
    Trie() {}
    Trie(vector<string> entries) {
        for (auto s:entries)
            add(s);
    }
    void add(string s) {
        TrieNode* curr = root;
        for(int i=0;i<s.length();i++) {
            curr->addChildIfAbsent(s[i]);
            curr = curr->getChild(s[i]);
            curr->incrSize(1);
        }
    }
    int find(string s) {
        TrieNode* curr = root;
        for (int i=0;i<s.length();i++) {
            curr = curr->getChild(s[i]);
            if(!curr) return 0;
        }
        return curr->getSize();
    }
};

int main() {
	// your code goes here
	int n;
	cin >> n;
	if(n<=0) return 0;
	string add = "add";
	string find = "find";
	Trie* trie = new Trie();
	for(int i=0;i<n;i++) {
	    string command,s;
	    cin >> command;
	    cin >> s;
	    if(!command.compare(add)) trie->add(s);
	    if(!command.compare("find")) cout<<trie->find(s)<<"\n";
	}
}
