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

liftTruckList * prepareTrucks(palletList * pList, liftTruckList * trucks){
    //Pasa de una lista de pedidos a la cola de los montacargas
    int pListSize = pList->getQuantity();
    int trucksSize = trucks->size(); 
    while (pList->isEmpty() == false){
        palletNode * tmp = pList->remove(pList->firstNode);
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
        //trucks->firstNode->data->queue->print();
    }
    return trucks;
}

void movePallets(liftTruckList * trucks, palletList * finalList, palletStackList * storage, palletList * order){
    liftTruckList * loadedTrucks = prepareTrucks(order, trucks);
    liftTruckNode * tmpTruck = trucks->firstNode;
    while (trucks->isEmpty() != true){      //mientras haya montacargas
        while(tmpTruck->data->queue->isEmpty() != true){        //mientras la cola de cada montacargas tenga trabajo
            cout << "Llegue" << endl;
            palletNode * tmpPallet = tmpTruck->data->queue->firstNode;
            palletStackNode * tmpPalletStackStorage = storage->firstNode;
            for (int i = 0; i < storage->getQuantity(); i++){       //recorre la bodega buscando coincidencia entre montacargas y producto
                cout << "Llegue" << endl;
                palletNode * tmpPalletStorage = tmpPalletStackStorage->data->firstNode;
                if (tmpPalletStorage->data->name == tmpPallet->data->name && tmpPalletStorage->data->amount == tmpPallet->data->amount){
                    finalList->addStart(tmpPalletStorage);
                    tmpPalletStackStorage->data->pop();
                    break;
                }
                else{
                    tmpPalletStorage = tmpPalletStorage->next;

                }
            }
            tmpTruck->data->queue->dequeue2();
        }
        trucks->deleteFirst();
    } 
}

int main(){ 

    palletQueue * queue1 = new palletQueue();
    palletQueue * queue2 = new palletQueue();
    cout << 1 << endl;

    liftTruck * truck1 = new liftTruck(5,queue1);
    liftTruck * truck2 = new liftTruck(5,queue2);
    liftTruckNode * node1 = new liftTruckNode(truck1);
    liftTruckNode * node2 = new liftTruckNode(truck2);
    liftTruckList * truckList = new liftTruckList();
    cout << 2 << endl;
    truckList->add(node1);
    truckList->add(node2);
    palletNode * pNode1 = new palletNode("Galletas",25,"kg");
    palletNode * pNode2 = new palletNode("Coca Cola",50,"l");
    palletNode * pNode3 = new palletNode("Manzanas",15,"kg");
    cout << 3 << endl;

    palletList * pList1 = new palletList();
    palletList * pList2 = new palletList();
    palletList * pList3 = new palletList();
    cout << 4 << endl;

    pList1->addStart(pNode1);
    pList1->addStart(pNode1);
    pList1->addStart(pNode1);

    pList2->addStart(pNode2);

    pList3->addStart(pNode3);
    pList3->addStart(pNode3);
    cout << 5 << endl;

    palletStackList * storage = new palletStackList();
    cout << 6 << endl;

    //liftTruckList * list = prepareTrucks(pList1,truckList);

    palletList * finalList = new palletList();
    cout << 7 << endl;

    palletList * order = new palletList();
    order->addStart(pNode1);
    cout << 8 << endl;

    movePallets(truckList, finalList, storage, order);
}