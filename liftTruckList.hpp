#include "liftTruckNode.hpp"

#ifndef LIFTTRUCKLIST
#define LIFTTRUCKLIST

struct liftTruckList{
    liftTruckNode * firstNode;

    liftTruckList(){
        firstNode = NULL;
    }

    bool isEmpty(){
        return firstNode == NULL;
    }

    int size(){
        //Returns an intiger with the size of the stack
        if (isEmpty()){
            return 0;
        }
        else{
            int liftTruckAmount = 0;
            liftTruckNode * tmp = firstNode;
            while (tmp != NULL){
                liftTruckAmount += 1;
                tmp = tmp->next;
            }
            return liftTruckAmount;
        }
    }

    void add(liftTruckNode * newNode){
        if (isEmpty()){
            firstNode = newNode;
        }
        else{
            newNode->next = firstNode;
            firstNode = newNode;
        }
    }

    void deleteFirst(){
        if (isEmpty()){
            cout << "Cannot delete a node from an empty list." << endl;
        }
        else{
            liftTruckNode * tmp = firstNode;
            firstNode = firstNode ->next;
            tmp->next = NULL;
        }
    }

};

#endif