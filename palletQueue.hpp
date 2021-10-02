#include "palletNode.hpp"

#ifndef PALLET_QUEUE
#define PALLET_QUEUE

struct palletQueue{
    palletNode * firstNode;

    palletQueue(){
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
    void add(string _name, int _amount, string _unit){
        palletNode * tmp = new palletNode(_name,_amount, _unit);
        if (isEmpty()){
            firstNode = tmp;
        }
        else{
            tmp->next = firstNode;
            firstNode = tmp;
        }
    }

    palletNode * front(){
        if (isEmpty()){
            cout << "Empty stack given, there is no data in this queue."<< endl;
            return NULL;
        }
        else{
            palletNode * tmp = firstNode;
            while (tmp->next != NULL){
                tmp = tmp->next;
            }
            return tmp;
        }
    }

    palletNode * dequeue(){
        if (isEmpty()){
            cout << "Empty stack given, there is no data to dequeue." << endl;
            return NULL;
        }
        else{
            palletNode * tmp = firstNode;
            while (tmp->next != NULL){
                
                tmp = tmp->next;
            }
            palletNode * res = tmp;
            tmp = NULL;
        }
    }

    void print(){
        if (isEmpty()){
            cout << "Empty queue given." << endl;
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