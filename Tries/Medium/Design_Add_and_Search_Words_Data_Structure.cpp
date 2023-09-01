// Using Map (gives TLE) ------------------->>>>>>>>>>>>>>>>>>>>

class WordDictionary {
private:
    unordered_map<int, vector<string>> words;
    bool isEqual(string s1, string s2) {
        for(int i=0; i<s1.size(); i++) {
            if(s2[i] == '.') continue;
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }

public:
    WordDictionary() {}
    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto str: words[word.size()]) {
            if(isEqual(str, word)) return true;
        }
        return false;
    }
};








// Solution 2 (Using Trie) --------------->>>>>>>>>>>>>>>>>>>>>

class WordDictionary {
private:
    class Node {
    public:
        Node* children[26];
        bool endOfWord;
        Node() {
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            endOfWord = false;
        }
    };

    Node* root = new Node();

public:
    WordDictionary() {}
    
    void addWord(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) {
                curr->children[idx] = new Node();
            }
            if(i == word.length()-1) {
                curr->children[idx]->endOfWord = true;
            }

            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        Node *curr = root;
        return find(word,curr);
    }

    bool find(string word, Node* curr) {
        for(int i=0; i<word.length(); i++) {
            if(word[i] == '.') {
                for(int j=0; j<26; j++) {
                    if(curr->children[j] != NULL 
                        && find(word.substr(i+1),curr->children[j])) {
                        return true;
                    }
                }
                return false;
            }

            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL) {
                return false;
            }

            if(i == word.length()-1 && !curr->children[idx]->endOfWord) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->endOfWord;
    }
};






/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
