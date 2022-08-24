// Title: Implement Trie (Prefix Tree)
// Description:
//     A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
//     There are various applications of this data structure, such as autocomplete and spellchecker.
//     Implement the Trie class:
//         - Trie() Initializes the trie object.
//         - void insert(String word) Inserts the string word into the trie.
//         - boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
//         - boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
// Link: https://leetcode.com/problems/implement-trie-prefix-tree/

// Time complexity: O(n) for { insert(word), search(word), startsWith(prefix) }
// Space complexity: O(n)
class Trie {
private:
    std::string key;
    bool isWordEnd;
    std::array<Trie *, 26> children;
    
public:
    Trie() {
        this->key = "";
        this->isWordEnd = false;
        std::fill(this->children.begin(), this->children.end(), nullptr);
    }
    
    void insert(std::string word) {
        // if the word is empty
        if (word == "") {
            // mark the current node as a word end
            this->isWordEnd = true;
            return;
        }
        
        Trie *&childNode = this->children[word[0] - 'a'];
        
        // if there is no child node for the word to go
        if (childNode == NULL) {
            // insert a new node with the word as the key
            Trie *newNode = new Trie(); {
                newNode->key = word;
                newNode->isWordEnd = true;
            }
            childNode = newNode;
            return;
        }
        
        std::string &childKey = childNode->key;
        
        // find the end index of common prefix of the word and the child key
        std::size_t matchEndIndex = 0;
        while (
            matchEndIndex != word.length() && matchEndIndex != childKey.length()
            && word[matchEndIndex] == childKey[matchEndIndex]
        ) ++matchEndIndex;
        
        // if the child key is not full matched
        if (matchEndIndex != childKey.length()) {
            // split the prefix of the child key into a new node
            Trie *newNode = new Trie(); {
                newNode->key = childKey.substr(0, matchEndIndex);
                newNode->children[childKey[matchEndIndex] - 'a'] = childNode;
            }
            childKey = childKey.substr(matchEndIndex, std::string::npos);
            childNode = newNode;
        }
        
        // insert the remaining suffix of the word into the child node
        childNode->insert(word.substr(matchEndIndex, std::string::npos));
    }
    
    bool search(std::string word) {
        // if the word is empty
        if (word == "") {
            // the word is found if the current node is a word end
            return this->isWordEnd;
        }
        
        Trie *&childNode = this->children[word[0] - 'a'];
        
        // if there is no child node for the word to go
        if (childNode == NULL) {
            // the word cannot be found
            return false;
        }
        
        std::string &childKey = childNode->key;
        
        // find the end index of common prefix of the word and the child key
        std::size_t matchEndIndex = 0;
        while (
            matchEndIndex != word.length() && matchEndIndex != childKey.length()
            && word[matchEndIndex] == childKey[matchEndIndex]
        ) ++matchEndIndex;
        
        // if the child key is not full matched
        if (matchEndIndex != childKey.length()) {
            // the word cannot be found
            return false;
        }
        
        // search the remaining suffix of the word from the child node
        return childNode->search(word.substr(matchEndIndex, std::string::npos));
    }
    bool startsWith(std::string prefix) {
        // if the prefix is empty
        if (prefix == "") {
            // the prefix is found
            return true;
        }
        
        Trie *&childNode = this->children[prefix[0] - 'a'];
        
        // if there is no child node for the prefix to go
        if (childNode == NULL) {
            // the prefix cannot be found
            return false;
        }
        
        std::string &childKey = childNode->key;
        
        // find the end index of common prefix of the prefix and the child key
        std::size_t matchEndIndex = 0;
        while (
            matchEndIndex != prefix.length() && matchEndIndex != childKey.length()
            && prefix[matchEndIndex] == childKey[matchEndIndex]
        ) ++matchEndIndex;
        
        // if the prefix is full matched
        if (matchEndIndex == prefix.length()) {
            // the prefix is found
            return true;
        }
        
        // if the child key is not full matched
        if (matchEndIndex != childKey.length()) {
            // the prefix cannot be found
            return false;
        }
        
        // search the remaining suffix of the prefix from the child node
        return childNode->startsWith(prefix.substr(matchEndIndex, std::string::npos));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
