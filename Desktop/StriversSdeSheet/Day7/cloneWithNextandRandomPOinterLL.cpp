#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
void insertAtTail(LinkedListNode<int>* &head, LinkedListNode<int>* &tail, int d){
    LinkedListNode<int>* newNode = new LinkedListNode<int>(d);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int>*cloneHead = NULL;
    LinkedListNode<int>*cloneTail = NULL;
    LinkedListNode<int> *temp = head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    //map
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*>mpp;
    temp = head;
    LinkedListNode<int>* cloneTemp = cloneHead;
    while(temp!=NULL){
        mpp[temp] = cloneTemp;
        temp = temp->next;
        cloneTemp = cloneTemp->next;
    }
    temp = head;
    cloneTemp = cloneHead;
    while(temp!=NULL){
        cloneTemp->random = mpp[temp->random];
        temp = temp->next;
        cloneTemp = cloneTemp->next;
    }
    return cloneHead;
}
