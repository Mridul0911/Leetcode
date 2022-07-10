class LRUCache {
public:
        class Node{
          public:
                int key;
                int val;
                Node *next;
                Node *prev;
                Node(int key,int val)
                {
                        this->key=key;
                        this->val=val;
                }
        };
        Node *head=new Node(-1,-1);
        Node *tail=new Node(-1,-1);
        int cap;
        unordered_map<int,Node*> mp;
        
                
        
    LRUCache(int capacity) {
      ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
        
        cap=capacity;
            head->next=tail;
            tail->prev=head;
    }
    void addNode(Node * newnode) {
        Node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
  }

  void deleteNode(Node * delnode) {
    Node * delprev = delnode -> prev;
    Node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
                Node *res=mp[key];
                int value=res->val;
                mp.erase(key);
                deleteNode(res);
                addNode(res);
                mp[key]=head->next;
                return value;
        }
            return -1;
    }
    
    void put(int key, int value) {
             ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
        if(mp.find(key)!= mp.end()) 
        {
            Node *existingnode=mp[key];
            mp.erase(key);
            deleteNode(existingnode);
        }
        if(mp.size()==cap) 
        {
            mp.erase(tail->prev->key);
           deleteNode(tail->prev);
        }
       addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */