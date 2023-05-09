// Title: LRU Cache
// Description:
//     Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//     Implement the LRUCache class:
//         LRUCache(int capacity)
//             Initialize the LRU cache with positive size capacity.
//         int get(int key)
//             Return the value of the key if the key exists, otherwise return -1.
//         void put(int key, int value)
//             Update the value of the key if the key exists.
//             Otherwise, add the key-value pair to the cache.
//             If the number of keys exceeds the capacity from this operation, evict the least recently used key.
//     Follow up:
//         Could you do get and put in O(1) time complexity?
// Link: https://leetcode.com/problems/lru-cache/

// Time complexity: O(1) for { get(key), put(key, value) }
// Space complexity: O(n)
struct LinkListNode {
    LinkListNode *prev;
    LinkListNode *next;
    int key;
    int value;
    
    LinkListNode(int key, int value): prev(NULL), next(NULL), key(key), value(value) {}
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, LinkListNode *> nodeLocation;
    LinkListNode *dummyHead;
    LinkListNode *dummyTail;
    
    void removeNode(LinkListNode *node) {
        // take the note out of its current position
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void appendNode(LinkListNode *node) {
        // put the node at the last position
        node->next = dummyTail;
        node->prev = dummyTail->prev;
        dummyTail->prev->next = node;
        dummyTail->prev = node;
    }
    void renewNode(LinkListNode *node) {
        // skip this step if the node is already the newest
        if (node->next == dummyTail) return;
        
        removeNode(node);
        appendNode(node);
    }
    
public:
    LRUCache(int capacity): capacity(capacity) {
        dummyHead = new LinkListNode(0xDEAD, 0);
        dummyTail = new LinkListNode(0xBEEF, 0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int key) {
        if (nodeLocation.count(key) != 0) {
            LinkListNode *node = nodeLocation[key];
            renewNode(node);
            return node->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (nodeLocation.count(key) != 0) {
            LinkListNode *node = nodeLocation[key];
            renewNode(node);
            node->value = value;
        } else {
            if (capacity > 0) {
                // create a new node with the value
                LinkListNode *node = new LinkListNode(key, value);
                
                appendNode(node);
                nodeLocation.emplace(key, node);
                capacity--;
            } else {
                // take the first (oldest) note out and reuse it
                LinkListNode *node = dummyHead->next;
                nodeLocation.erase(node->key);
                
                node->key = key;
                node->value = value;
                
                renewNode(node);
                nodeLocation.emplace(key, node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
