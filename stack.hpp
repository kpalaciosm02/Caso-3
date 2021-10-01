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
        if (isEmpty()){
            node * tmp = new node(_data);
            firstNode = tmp;
            //free(tmp);
        }
        else{
            node * tmp = new node(_data);
            tmp->next = firstNode;
            firstNode = tmp;
            //free(tmp);
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