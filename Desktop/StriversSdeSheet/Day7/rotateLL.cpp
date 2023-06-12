/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     int len=1;
     Node* temp = head;
     while(temp->next!=NULL){
          len++;
          temp = temp->next;
     }
     temp->next = head; //circular bna diya
     k = k%len;
     int a = len-k;
     while(a--){
          temp = temp->next;
     }
     head = temp->next;
     temp->next = NULL;
     return head;
}