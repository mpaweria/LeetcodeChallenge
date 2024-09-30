class Node {
    public:
        int key, value;
        Node* prev, *next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache {
public:

    int size;
    unordered_map<int, Node*>map;

    Node* head = new Node(-1, -1), *tail = new Node(-1, -1);

    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())
            return -1;

        Node* temp = map[key];
        deleteNode(temp);
        insertAtHead(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node* temp = map[key];
            temp->value = value;
            deleteNode(temp);
            insertAtHead(temp);
        } else {
            Node* newNode = new Node(key, value);
            if(map.size() == size) {
                Node* toDel = tail->prev;
                map.erase(toDel->key);
                deleteNode(tail->prev);
                insertAtHead(newNode);
                map[key] = newNode;
                delete toDel;
            } else {
                insertAtHead(newNode);
                map[key] = newNode;
            }
        }
    }
};