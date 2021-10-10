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

liftTruck *prepareTruck(palletList *pList, liftTruck *truck)
{
    while (pList->isEmpty() == false)
    {
        palletNode* temp=pList->firstNode;
        pList->firstNode=pList->firstNode->next;
        temp->next=NULL;
        truck->queue->addNode(temp);
    }
    return truck;
}

void movePallets(liftTruck *truck, palletList *finalList, palletStackList *storage, palletList *order)
{
    truck=prepareTruck(order,truck);

    while (truck->queue->isEmpty()==false)
    {
        palletNode *tempOrder=truck->queue->dequeue2();
        palletStackNode *tempStorage = storage->firstNode;
        while(tempStorage != NULL)
        {
            if (tempStorage->data->firstNode->data->name == tempOrder->data->name && tempStorage->data->firstNode->data->amount == tempOrder->data->amount)
            {
                palletNode *res = tempStorage->data->pop();
                res->next=NULL;
                finalList->addStart(res);
                break;
            }
            else;
            tempStorage=tempStorage->next;
        }

        
    }
    finalList->print();
}

int main(){ 

    palletQueue * queue1 = new palletQueue();
    palletQueue * queue2 = new palletQueue();

    liftTruck * truck1 = new liftTruck(5,queue1);
    liftTruckNode * node1 = new liftTruckNode(truck1);
    palletNode * pNode1 = new palletNode("Galletas",25,"kg");
    palletNode * pNode2 = new palletNode("Coca Cola",50,"l");
    palletNode * pNode3 = new palletNode("Manzanas",15,"kg");


    palletList * pList1 = new palletList();
    palletList * pList2 = new palletList();
    palletList * pList3 = new palletList();

    palletStack * pStack1 = new palletStack();
    palletStack * pStack2 = new palletStack();
    palletStack * pStack3 = new palletStack();

    pStack1->push("Galletas",24,"kg");
    pStack1->push("Galletas",25,"kg");
    /*pStack1->push("Galletas",25,"kg");
    pStack1->push("Galletas",25,"kg");
    pStack1->push("Galletas",25,"kg");
    pStack1->push("Galletas",25,"kg");
    pStack1->push("Galletas",25,"kg");
    pStack1->push("Galletas",25,"kg");*/


    pStack2->push("Coca Cola",58,"l");
    /*pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");
    pStack2->push("Coca Cola",50,"l");*/

    pStack3->push("Manzanas",75,"kg");
    pStack3->push("Manzanas",15,"kg");
    /*pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");
    pStack3->push("Manzanas",15,"kg");*/

    palletStackNode * pSNode1 = new palletStackNode(pStack1);
    palletStackNode * pSNode2 = new palletStackNode(pStack2);
    palletStackNode * pSNode3 = new palletStackNode(pStack3);
    
    pList1->addStart(pNode1);

    pList2->addStart(pNode2);

    pList3->addStart(pNode3);

    palletStackList * storage = new palletStackList();

    storage->addStack(pSNode1);
    storage->addStack(pSNode2);
    storage->addStack(pSNode3);

    palletList * finalList = new palletList();
 
    palletList * order = new palletList();
    order->addStart(pNode3);
    order->addStart(pNode2);
    order->addStart(pNode1);

    movePallets(truck1, finalList, storage, order);
    //finalList->firstNode->print();
}