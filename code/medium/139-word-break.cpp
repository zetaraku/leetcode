// Title: Word Break
// Description:
//     Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
//     Note that the same word in the dictionary may be reused multiple times in the segmentation.
// Link: https://leetcode.com/problems/word-break/

// Time complexity: O(m*n)
// Space complexity: O(n)
// Variables:
//     m = length of string s
//     n = total length of wordDict
class Trie {
public:
    bool isWordEnd;
    std::array<Trie *, 26> children;

    Trie() {
        this->isWordEnd = false;
        std::fill(this->children.begin(), this->children.end(), nullptr);
    }
    
    void insert(const std::string &word) {
        Trie *node = this;
        
        for (char c: word) {
            Trie *&childNode = node->children[c - 'a'];
            
            if (childNode == NULL) {
                childNode = new Trie();
            }
            
            node = childNode;
        }
        
        node->isWordEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        // make an empty trie
        Trie *trieRoot = new Trie(); {
            // the string s is well-segmented too if we are at the root (insert "")
            trieRoot->isWordEnd = true;
        }
        
        // put every words into the trie
        for (const std::string &word: wordDict) {
            trieRoot->insert(word);
        }
        
        // start matching from the trie root
        std::unordered_set<Trie *> currentNodes; {
            currentNodes.insert(trieRoot);
        }
        
        // match each char in s
        for (char c: s) {
            // the next nodes after matching the current char
            std::unordered_set<Trie *> nextNodes;
            
            // for each current node
            for (Trie *currentNode: currentNodes) {
                // match the char
                Trie *nextNode = currentNode->children[c - 'a'];
                
                // drop the current node if the char cannot be matched
                if (nextNode == NULL) continue;
                
                // move the current node to the next node
                nextNodes.insert(nextNode);

                // if a possible word end is found after matching the char
                if (nextNode->isWordEnd) {
                    // start a new matching from the trie root
                    nextNodes.insert(trieRoot);
                }
            }
            
            // update the current nodes
            currentNodes = std::move(nextNodes);
        }
        
        // the string s can be well-segmented if any node is at a word end
        return std::any_of(
            currentNodes.begin(), currentNodes.end(),
            [](Trie *node) { return node->isWordEnd; }
        );
    }
};
