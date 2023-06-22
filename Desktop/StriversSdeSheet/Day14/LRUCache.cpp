#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*>mpp;
    int cap;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    void deleteNode(node* delNode){
        node* delprev = delNode->prev;
        node* delNext = delNode->next;
        delprev->next = delNext;
        delNext->prev = delprev;
    }

    int get(int key)
    {
        if(mpp.find(key)!=mpp.end()){
            node* resNode = mpp[key];
            int ans = resNode->val;
            mpp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mpp[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mpp.find(key)!=mpp.end()){
            node* existingNode = mpp[key];
            mpp.erase(key);
            deleteNode(existingNode);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mpp[key] = head->next;

    }
};
