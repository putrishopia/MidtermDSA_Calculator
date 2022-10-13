#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>

template <typename DataType>
class order {
private:
	struct Node
	{
		DataType data;
		Node* next;
	};
	Node* head;
public:
	order() { head = NULL; }
	// push an element of input to be part of calculation
	void push(DataType element, bool output = false)
	{
    //   cout << "element being pushed: " <<element << endl;
		struct Node* newNode;
		newNode = new Node();
		newNode->data = element;
		newNode->next = head;
		head = newNode;
	}
    // debugger function to test the loop process
    void loop(){
        struct Node* temp;
        temp = head;
        while (temp != NULL){
            temp = temp->next;
        }
    }
	// delete node from linked list
	DataType pop()
	{
		struct Node* temp;
		temp = head;
		DataType poppedValue = head->data;
		head = head->next;
		temp->next = NULL;
		free(temp);
		return poppedValue;
	}
    // calling the head of the linked list
	DataType top()
	{
		return head->data;
	}
    // empty linked list checker
	bool empty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
};

#endif // ORDER_H
