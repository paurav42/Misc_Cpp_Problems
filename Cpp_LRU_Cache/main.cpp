

#include<iostream>
#include<unordered_map>
#include<list>

template<typename Key, typename Value>
class Node{
    public:
    Key key;
    Value val;
    Node* next;
    Node* prev;

    Node(Key _key, Value _val){
        key = _key;
        val = _val;
    }
};

template<typename Key, typename Value>
class LRUCache{
    
    public:
    Node* head = new Node(Key {},Value {});
    Node* tail = new Node(Key{},Value{});

    int cap;
    unordered_map<Key, Node*> mp;

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* newnode){
        // add right after head
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        temp->prev = newnode;
        head->next = newnode;

    }

    void deletenode(Node* delnode){
        //delete just before head
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void get(Key getkey){
        //if key exists , take node address, 
        if(mp.find(getkey)!=mp.end()){ //key is available
            Node* resnode = mp[getkey];
            Value res = resnode->val;
            mp.erase(getkey);
            deletenode(resnode);
            addnode(resnode);
            mp[getkey] = head->next;
            return res;
        }
        return -1;
    }

    void put(Key putkey, Value putval){
        //if key does not exist
        if(mp.find(putkey)!=mp.end()){
            Node* existing = mp[putkey];
            mp.erase(putkey);
            deletenode(existing);
        }
        //if size > cap
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new Node(putkey, putval));
        mp[putkey] = head->next;

    }





    // public:
    // explicit LRUCache(const int capacity);
    // bool has(const Key& key) const; // get
    // Value& operator[](const Key& key);
    // void invalidate(const Key& key); // 
    // private:
    // // ADD DECLARATIONS HERE

};




int main(){

    LRUCache<int,int> c1(3);


    return 0;
}