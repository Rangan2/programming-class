#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams (vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (size_t i = 0; i < strs.size(); i++) {
        string sortedString = strs[i];
        
        sort(sortedString.begin(), sortedString.end());
        anagramGroups[sortedString].push_back(strs[i]);
    }
    
    
                   

    vector<vector<string>> result;
    for (const auto& pair : anagramGroups) {
        result.push_back(pair.second);
        
    }
    return result;
    
}

int main () {
    vector<string> strs = {"eat", "nat", "bat", "tea", "tan", "ate"};
    vector<vector<string>> grouped = groupAnagrams(strs);

    cout << "{";
    for (const auto& group : grouped) {
        cout << "{";
        for (const auto& i : group) {
            cout << i <<" ";
        }
        cout << "}";
    }
    cout << "}";

    return 0;
}

