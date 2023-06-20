#include <bits/stdc++.h> 
// Stack class.
class Stack {
    private:
    int* arr;
    int TOP;
    int capacity;
    
public:
    
    
    Stack(int capacity) {
        arr = new int[capacity];
        TOP=-1;
        this->capacity = capacity;
    }

    void push(int num) {
        if(TOP==capacity){
            return;
        }
        TOP++;
        arr[TOP]=num;
    }

    int pop() {
        if(TOP == -1)
            return -1;
        int temp = arr[TOP];
        TOP--;
        return temp;
    }
    
    int top() {
        if(TOP>=0){
           return arr[TOP];
        }
        return -1;
    }
    
    int isEmpty() {
        if(TOP==-1){
            return 1;
        }
        else return 0;
    }
    
    int isFull() {
        if(TOP==capacity) return 1;
        else return 0;
    }
    
};