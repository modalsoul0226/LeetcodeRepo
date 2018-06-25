#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         return s == t;
        if (s.size() != t.size()) return false;
        
        int tab[26]; memset(tab, 0, sizeof(tab));
        for (int i = 0; i < s.size(); i++) {
            tab[s[i] - 'a']++;
            tab[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++)
            if (tab[i])
                return false;
        return true;
    }
};