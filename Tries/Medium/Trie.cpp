#include<iostream>
#include<vector>
using namespace std;

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

void insert(string word) {
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
    Node* curr = root;
    for(int i=0; i<word.length(); i++) {
        int idx = word[i] - 'a';

        if(curr->children[idx] == NULL) {
            return false;
        }
        if(i == word.length()-1 && !curr->children[idx]->endOfWord) {
            return false;
        }

        curr = curr->children[idx];
    }
    return true;
}

int main() {
    string words[] = {"the","a","there","their","any"};

    int n = sizeof(words)/sizeof(words[0]);

    for(int i=0; i<n; i++) {
        insert(words[i]);
    }

    cout<<search("their")<<endl;
    cout<<search("thor")<<endl;
    cout<<search("an")<<endl;
    
    return 0;
}
