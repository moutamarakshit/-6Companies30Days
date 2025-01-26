class LRUCache {
public:
    // creating the Node class
    class Node {
        public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };
    // creating the dll
    Node* head = new Node(0, 0);
    Node* tail = new Node(0,0);
    

    unordered_map<int, Node*>mpp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if (mpp.size() == cap) {
                Node* temp = tail->prev;
                mpp.erase(temp->key);
                deleteNode(temp);
                delete temp; // to avoid memory leak
            }
            // create the new node regardless
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mpp[key] = newNode;
            
        }
    }
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insertAfterHead(Node* node) {
        Node* headN = head->next;
        head->next = node;
        node->next = headN;
        headN->prev = node;
        node->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
