class LRUCache {
public:
    int size;
    struct node {
        int key;
        int data;
        node*left;
        node*right;
        node(int k, int d) {
            key = k;
            data = d;
            left = right = nullptr;
        }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    
    void change(node* curr) {
        node* prev = curr->left;
        node* next = curr->right;

        prev->right = next;
        next->left = prev;

        curr->left = head;
        curr->right = head->right;
        head->right->left = curr;
        head->right = curr;
    }
    LRUCache(int capacity) {
        size = capacity;
        head->right = tail;
        tail->left = head;
    }
    unordered_map<int, node*>mp;

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        else {
            change(mp[key]);
            return mp[key]->data;
        }
    }
    
    void put(int key, int value) {
        if(get(key) == -1) {
            if(size == mp.size()) {
                node* curr = tail->left;
                curr->left->right = tail;
                tail->left = curr->left;
                mp.erase(curr->key);
                delete curr;  
            }
            node* curr = new node(key, value);
            curr->left = head;
            curr->right = head->right;
            head->right->left = curr;
            head->right = curr;

            //change(newnode);
            mp[key] = curr;
        }
        else {
            node*temp = mp[key];
            temp->data = value; 
            change(mp[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */