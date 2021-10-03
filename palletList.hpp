#include "palletNode.hpp"

#ifndef PALLET_LIST
#define PALLET_LIST


struct palletList
{
    palletNode*firstNode;

    palletList()
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
            palletNode *temp = firstNode;
            while(temp != NULL)
            {
                length += 1;
                temp = temp -> next;
            }
            return length;
        }
    }
    bool addStack(palletNode *pallet)
    {

        if (firstNode == NULL)
        {
            firstNode = pallet;
            return true;
        }
        else
        {
            palletNode *temp = firstNode;
            while (temp != NULL)
            {
                if (temp->next != NULL)
                    temp = temp->next;
                else
                {
                    temp -> next = pallet;
                    return true;
                }
            }
            return false;
        }
    }
    void removeStack(palletNode *pallet)
    {
        if (firstNode == NULL)
        return;
        else
        {
            palletNode *temp = firstNode;
            if (firstNode == pallet)
            {
                firstNode = firstNode -> next;
                return;
            }
            else
            {
                palletNode *last = firstNode;
                temp =temp -> next;
                while(temp != NULL)
                {
                    if (temp == pallet)
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
