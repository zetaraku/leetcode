// Title: Word Ladder
// Description:
//     A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s[1] -> s[2] -> ... -> s[k] such that:
//         - Every adjacent pair of words differs by a single letter.
//         - Every s[i] for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//         - s[k] == endWord
//     Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
// Link: https://leetcode.com/problems/word-ladder/

// Time complexity: O(m*n^2)
// Space complexity: O(m*n)
// Variables:
//     m = size of the wordList
//     n = length of any word
class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
        // put all words in the dictionary into a word set to lookup faster
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        
        // start breadth-first search (BFS) with the begin word and an end-of-level mark ("")
        std::queue<std::string> wordQueue; {
            wordQueue.push(beginWord);
            wordQueue.push("");
        }
        
        // record the current searching depth
        std::size_t currentDepth = 1;
        
        while (true) {
            // take out the next word to process
            std::string currentWord = wordQueue.front(); wordQueue.pop();
            
            // end if an end-of-level mark is reached before a word
            if (currentWord == "") break;
            
            // return the number of words if we reached the end word
            if (currentWord == endWord) return currentDepth;
            
            std::string adjacentWord = currentWord;
            
            // for each position in the current word
            for (std::size_t i = 0; i != currentWord.size(); ++i) {
                // for each letter in the alphabet ...
                for (char c = 'a'; c <= 'z'; ++c) {
                    // ... that is not the same as the letter at the current position
                    if (c == currentWord[i]) continue;
                    
                    // replace the letter at the position with a differernt letter to make an adjacent word
                    adjacentWord[i] = c;
                    
                    // if the adjacent word is in the word set
                    if (wordSet.count(adjacentWord) != 0) {
                        // push the adjacent word into the queue
                        wordQueue.push(adjacentWord);
                        
                        // remove the word from the word set so we won't go back to the word
                        wordSet.erase(adjacentWord);
                    }
                }
                
                // restore the letter at the position with the original letter
                adjacentWord[i] = currentWord[i];
            }
            
            // check if this node is at the end of the current level
            if (wordQueue.front() == "") {
                // remove the end-of-level mark
                wordQueue.pop();
                
                // append an end-of-level mark to mark the end of the next level
                wordQueue.push("");
                
                // next level has one more word in the sequence
                currentDepth += 1;
            }
        }
        
        // the end word cannot be reached with the words in the dictionary
        return 0;
    }
};
