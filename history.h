#ifndef HISTORY_H
#define HISTORY_H


// Linked List Node
class Node
{
  public:
    string data;
    Node* next;
};

void push(Node** headRef, string newData)
{
    // make a new node in a heap and set its data
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// We put a delete linked list here
void deleteHistory(Node** headRef, string key)
{
    // Store the head node
    Node* tmp = *headRef;
    Node* prev = NULL;
    // If head node itself holds the key to be deleted
    if(tmp != NULL && tmp->data == key)
    {
        *headRef = tmp->next;
        delete tmp;
        return;
    }
    // This else function is to find the key that needs to be deleted
    // prev->next
    else
    {
        while(tmp != NULL && tmp->data != key)
        {
            prev = tmp;
            tmp = tmp->next;
        }

        if (tmp == NULL)
            return;

        prev->next = tmp->next;

        delete tmp;
    }
}

//
void printHistory(Node* head)
{
    Node* ptr = head;
    while (ptr)
    {
        int i=0;
		cout<<i<<ptr->data<<"\n ";
        ptr=ptr->next;
        i++;
    }
 }

#endif // HISTORY_H
