#include "palletNode.hpp"

#ifndef PALLET_STACK
#define PALLET_STACK

struct palletStack{
    palletNode * firstNode;

    palletStack(){
        firstNode = NULL;
    }

    bool isEmpty(){
        return firstNode == NULL;
    }

    int size(){
        if (isEmpty()){
            return 0;
        }
        else{
            int palletAmount = 0;
            palletNode * tmp = firstNode;
            while (tmp != NULL){
                palletAmount += 1;
                tmp = tmp->next;
            }
            return palletAmount;
        }
    }

    void push(string _name, int _amount, string _unit){
        palletNode * tmp = new palletNode(_name, _amount, _unit);
        if (isEmpty()){
            firstNode = tmp;
        }
        else{
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    palletNode * pop(){
        if (isEmpty()){
            cout << "Empty stack given, there is no data to pop." << endl;
            return NULL;
        }
        else{
            palletNode * tmp = firstNode;
            firstNode = firstNode->next;
            return tmp;
        }
    }

    palletNode * top(){
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
            cout << "Empty stack given." << endl;
        }
        else{
            palletNode * tmp = firstNode;
            while (tmp != NULL){
                tmp->print();
                tmp = tmp->next;
            }
        }
    }
};

#endif