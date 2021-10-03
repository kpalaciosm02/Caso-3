#include <iostream>
using namespace std;

#ifndef NODE
#define NODE

struct node{
    //Node with an intiger as data
    int data;
    node * next;

    node(){
        //Constructor method
        data = 0;
        next = NULL;
    }

    node(int _data){
        //Constructor method
        data = _data;
        next = NULL;
    }

    void print(){
        //Prints the info of the node
        cout << "Node data: " << data << endl;
    }
};

#endif