#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {

    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    map<string,int> cache;
    string temp; stringstream ss(paragraph);

    while (ss >> temp) {
        int j = 0; string word = "";
        for (int i = 0; i < temp.length(); i++) {
            if (!isalpha(temp[i])) break;
            word += tolower(temp[i]);
        }
        
        if (cache.count(word)) cache[word]++;
        else cache[word] = 1;
    }


    vector<vector<string> > tab(1000);
    for (int i = 0; i < tab.size(); i++) tab[i] = vector<string>();
    for (map<string,int>::iterator it = cache.begin(); it != cache.end(); it++) {
        tab[it->second].push_back(it->first); 
    }
    
    set<string> ban; for (int i = 0; i < banned.size(); i++) ban.insert(banned[i]);
    for (int i = tab.size() - 1; i > 0; i--) {
        for (int j = 0; j < tab[i].size(); j++)
            if (!ban.count(tab[i][j])) { cout << tab[i][j] << endl; return 0; }
    }
}