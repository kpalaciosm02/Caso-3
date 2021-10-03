#include "palletStack.hpp"

#ifndef PALLET_STACKLIST
#define PALLET_STACKLIST

struct palletStackNode{
    //Node with a pallet as data
    palletStack * data;
    palletStackNode * next;

    palletStackNode(){
        //Constructor method
        data = new palletStack();
        next = NULL;
    }

    palletStackNode(palletStack *stack){
        //Constructor method
        data = stack;
        next = NULL;
    }

    void print(){
        //Prints the data of the node
        data->print();
    }
};

struct palletStackList
{
    palletStackNode *firstNode;

    palletStackList()
    {
        firstNode = NULL;
    }
    bool isEmpty()
    {
        if (firstNode == NULL)
            return true;
        else
            return false;
    }
    int getQuantity()
    {
        if (firstNode == NULL)
        return 0;
        else
        {
            int length = 0;
            palletStackNode *temp = firstNode;
            while(temp != NULL)
            {
                length += 1;
                temp = temp -> next;
            }
            return length;
        }
    }
    bool addStack(palletStackNode *stack)
    {

        if (firstNode == NULL)
        {
            firstNode = stack;
            return true;
        }
        else
        {
            palletStackNode *temp = firstNode;
            while (temp != NULL)
            {
                if (temp->next != NULL)
                    temp = temp->next;
                else
                {
                    temp -> next = stack;
                    return true;
                }
            }
            return false;
        }
    }
    void removeStack(palletStackNode *stack)
    {
        if (firstNode == NULL)
        return;
        else
        {
            palletStackNode *temp = firstNode;
            if (firstNode == stack)
            {
                firstNode = firstNode -> next;
                return;
            }
            else
            {
                palletStackNode *last = firstNode;
                temp =temp -> next;
                while(temp != NULL)
                {
                    if (temp == stack)
                    {
                        last->next = temp->next;
                        return;
                    }
                    else
                    {
                        last = last->next;
                        temp = temp -> next;
                    }
                }
                return;
            }

        }

    }
};
#endif