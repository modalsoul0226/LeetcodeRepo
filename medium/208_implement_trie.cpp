#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    vector<Trie*> children;  
    bool ends; // whether it is the end of an word

    Trie() {
        this->children = vector<Trie*>(26, nullptr);
        this->ends = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // sanity check
        if (word.empty()) return;

        // store the first char
        int index = word[0] - 'a';
        if (!this->children[index]) {
            this->children[index] = new Trie();
        }

        // store the remaining chars
        if (word.length() == 1) {
            this->children[index]->ends = true;
            return;
        }
        this->children[index]->insert(word.substr(1));
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        // sanity check
        if (word.empty()) return true;

        // check the first char
        int index = word[0] - 'a';
        if (!this->children[index])
            return false;

        // check the remaining chars      
        if (word.length() == 1)
            return this->children[index]->ends;
        else
            return this->children[index]->search(word.substr(1));
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // sanity check
        if (prefix.empty()) return true;

        // check the first char
        int index = prefix[0] - 'a';
        if (!this->children[index])
            return false;

        // check the remaining chars      
        if (prefix.length() == 1)
            return true;
        else
            return this->children[index]->search(prefix.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << "\n";
}
