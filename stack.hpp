#include "node.hpp"

#ifndef STACK
#define STACK

struct stack{
    node * firstNode;

    stack(){
        firstNode = NULL;
    }

    bool isEmpty(){
        return firstNode == NULL;
    }

    void push(int _data){
        node * tmp = new node(_data);
        if (isEmpty()){
            firstNode = tmp;
        }
        else{
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    node * pop(){
        if (isEmpty()){
            cout << "Empty Stack given, there is no data to pop." << endl;
            return NULL;
        }
        else{
            node * tmp = firstNode;
            firstNode = firstNode->next;
            return tmp;
        }
    }

    node * top(){
        if (isEmpty()){
            cout << "Empty stack given, there is no data to pop." << endl;
            return NULL;
        }
        else{
            return firstNode;
        }
    }

    void print(){
        if (isEmpty()){
            cout << "Empty Stack given:" << endl;
        }
        else{
            node * tmp = firstNode;
            while (tmp != NULL){
                cout << tmp->data << "-> ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
        
};


#endif