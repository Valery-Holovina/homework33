//
//  MyStack.h
//  homework33
//
//  Created by Valery on 12.06.2025.
//

#ifndef MyStack_h
#define MyStack_h
#include <iostream>
using namespace std;

namespace myStack{
template <typename T>
class Node{
public:
    T info;
    Node* next;
    Node* prev;
    
    Node(T value){ info = value; next = prev=nullptr;}
};

template <typename U>
class Stack{
    Node<U>* head;
    Node<U>* current;
public:
    Stack(){
        head=current=nullptr;
    }
    ~Stack(){}
    
    bool isEmpty()const{
        return head == nullptr || current == nullptr;
    }
    
    U top()const{
        if(isEmpty()) throw "Stack is empty";
        return current->info;
    }
    
    void push_back(U value) {
        Node<U>* el = new Node<U>(value);
        if(isEmpty())
            head = current = el;
        else{
            current->next = el;
            el->prev = current;
            current = el;
        }
    }
    void pop_back() {
        if(isEmpty()) throw "Stack is empty";
        // only one left
        if(head==current){
            head = current = nullptr;
        }else{
            current = current->prev;
            delete current->next;
            current->next = nullptr;
        }
    }
    void showStack()const{
        if(isEmpty()) cout<<"Stack is empty"<<endl;
        else{
            Node<U>* p = head;
            while (p!=nullptr) {
                cout<<p->info<<" ";
                p = p->next;
                
            }
            cout<<endl;
        }
    }

};
}

#endif /* MyStack_h */
