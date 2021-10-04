#include "liftTruck.hpp"

#ifndef LIFTTRUCKNODE
#define LIFTTRUCKNODE

struct liftTruckNode{
    liftTruck * data;
    liftTruckNode * next;

    liftTruckNode(){
        data = new liftTruck();
        next = NULL;
    }

    liftTruckNode(liftTruck * _data){
        data = _data;
        next = NULL;
    }

    void print(){
        data->queue->print();
    }
};

#endif