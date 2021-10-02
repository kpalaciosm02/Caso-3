#include <iostream>
#include "node.hpp"
using namespace std;
#include "stack.hpp"
#include "palletStack.hpp"
#include "palletQueue.hpp"

int main(){ 
    /*palletStack * pila = new palletStack();
    cout << "Empty: " << pila->isEmpty() << endl;
    pila->print();
    pila->push("Arroz", 15, "kg");
    pila->push("Carne", 10, "kg");
    pila->push("Agua", 20, "l");
    cout << "Empty: " << pila->isEmpty() << endl;
    pila->print();
    cout << "Creando nodo" << endl;
    palletNode * nodo = pila->top();
    nodo->print();
    cout << "Probando top" << endl;
    pila->print();
    cout << "Size: " << pila->size() << endl;
    pila->pop();
    pila->print();*/

    palletQueue * queue = new palletQueue();
    cout << "Empty: " << queue->isEmpty() << endl;
    queue->print();
    queue->add("Arroz", 15, "kg");
    queue->add("Carne", 10, "kg");
    queue->add("Agua", 20, "l");
    cout << "Empty: " << queue->isEmpty() << endl;
    queue->print();
    cout << "Creando nodo" << endl;
    palletNode * nodo = queue->front();
    nodo->print();
    queue->dequeue();
    cout << "Quitando elemento" << endl;
    queue->print();
}