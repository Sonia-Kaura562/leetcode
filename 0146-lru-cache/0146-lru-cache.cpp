class LRUCache {
private:
    struct node {
        int key, value;
        node*prev = nullptr;
        node*next = nullptr;
        node(int k, int v) {
            key = k;
            value = v;
        } 
    };
    node*head = new node(-1, -1);
    node*tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*>mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(node*delNode) {
        node* temp = delNode->next;
        node* tempPrev = delNode->prev;
        temp->prev = tempPrev;
        tempPrev->next = temp;
        //delete delNode;
    }

    void insertNode(node*insertNode) {
        node* temp = head->next;
        temp->prev = insertNode;
        insertNode->next = temp;
        insertNode->prev = head;
        head->next = insertNode;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()) {
            int value = mp[key]->value;
            deleteNode(mp[key]);
           // node*newnode = new node(key, value);
           // mp[key] = newnode;
            insertNode(mp[key]);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            deleteNode(mp[key]);
            mp[key]->value = value;
            insertNode(mp[key]); 
        }
        else {
            if(mp.size() == cap) {
                mp.erase(tail->prev->key);
                node*lru = tail->prev;
                deleteNode(tail->prev);
                delete (lru);
            }
            node*newnode = new node(key, value);
            insertNode(newnode); 
            mp[key] = newnode;
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */