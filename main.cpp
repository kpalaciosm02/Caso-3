#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "node.hpp"
using namespace std;
#include "stack.hpp"
#include "palletStack.hpp"
#include "palletQueue.hpp"
#include "liftTruckList.hpp"
#include "palletStackList.hpp"
#include "palletList.hpp"

palletStackList * fill(){
    palletStackList * storage = new palletStackList();
    palletNode * pallet1 = new palletNode("Galletas",25,"kg");
    palletNode * pallet2 = new palletNode("Coca Cola",50,"l");
    palletNode * pallet3 = new palletNode("Manzanas",15,"kg");

    palletStack * stackGalletas = new palletStack();
    stackGalletas->push("Galletas",25,"kg");
    stackGalletas->push("Galletas",25,"kg");
    stackGalletas->push("Galletas",25,"kg");

    palletStack * stackCoca = new palletStack();
    stackCoca->push("Coca Cola",50,"l");
    stackCoca->push("Coca Cola",50,"l");
    stackCoca->push("Coca Cola",50,"l");
    stackCoca->push("Coca Cola",50,"l");
    stackCoca->push("Coca Cola",50,"l");

    palletStack * stackManzanas = new palletStack();
    stackManzanas->push("Manzanas",15,"kg");
    stackManzanas->push("Manzanas",15,"kg");

    palletStackNode * node1 = new palletStackNode(stackGalletas);
    palletStackNode * node2 = new palletStackNode(stackCoca);
    palletStackNode * node3 = new palletStackNode(stackManzanas);

    storage->addStack(node1);
    storage->addStack(node2);
    storage->addStack(node3);

    return storage;

}

liftTruckList * fillTrucks(){
    palletQueue * queue1 = new palletQueue();
    palletNode * node1 = new palletNode("Galletas",25,"kg");
    palletNode * node2 = new palletNode("Coca Cola",50,"l");
    palletNode * node3 = new palletNode("Manzanas",15,"kg");

    queue1->add("Galletas",25,"kg");
    queue1->add("Coca Cola", 50, "l");
    queue1->add("Manzanas",15,"kg");

    palletQueue * queue2 = new palletQueue();
    queue2->add("Galletas",25,"kg");
    queue2->add("Coca Cola", 50, "l");
    queue2->add("Manzanas",15,"kg");

    palletQueue * queue3 = new palletQueue();
    queue3->add("Galletas",25,"kg");
    queue3->add("Coca Cola", 50, "l");
    queue3->add("Manzanas",15,"kg");

    palletList * list = new palletList();
    list->add(node1);
    list->add(node2);
    list->add(node3);
    list->add(node1);
    list->add(node2);
    list->add(node3);
    list->add(node2);

}

void prepareTrucks(palletList * pList, liftTruckList * trucks){
    int pListSize = pList->getQuantity();
    int trucksSize = trucks->size(); 
    while (pList->isEmpty() == false){
        //cout << "pList size: " << pList->getQuantity() << endl;
        palletNode * tmp = pList->remove(pList->firstNode);
        //tmp->print();
        srand(time(NULL));
        int index = rand() % trucksSize;
        liftTruckNode * tmpTruck = trucks->firstNode;
        int counter = 0;
        while (counter != index + 1){
            if (counter == index){
                tmpTruck->data->queue->add(tmp->data->name,tmp->data->amount,tmp->data->unit);
                break;
            }
            else{
                tmpTruck = tmpTruck->next;
                counter += 1;
            }
            
        }

        //tmpTruck->data->queue->add(tmp->data->name,tmp->data->amount,tmp->data->unit);
        trucks->firstNode->data->queue->print();
        //trucks->firstNode->print();
    }

}

int main(){ 

    palletQueue * queue = new palletQueue();
    /*queue->add("Arroz", 15, "kg");
    queue->add("Carne", 10, "kg");
    queue->add("Agua", 20, "l");*/
    liftTruck * truck1 = new liftTruck(5,queue);
    liftTruck * truck2 = new liftTruck(5,queue);
    liftTruckNode * node1 = new liftTruckNode(truck1);
    liftTruckNode * node2 = new liftTruckNode(truck2);
    liftTruckList * truckList = new liftTruckList();
    truckList->add(node1);
    truckList->add(node2);
    //cout << truckList->size() << endl;
    palletNode * pNode1 = new palletNode("Galletas",25,"kg");
    palletNode * pNode2 = new palletNode("Coca Cola",50,"l");
    palletNode * pNode3 = new palletNode("Manzanas",15,"kg");

    palletList * pList = new palletList();
    pList->add(pNode1);
    pList->add(pNode2);
    pList->add(pNode3);

    prepareTrucks(pList,truckList);
}