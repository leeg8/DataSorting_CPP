#pragma once
#include <iostream>
using namespace std;
struct queueNode
{
	int data;
	queueNode* next;
};
class PriorityQueue {
private:
	queueNode* front;
	int size;
public:
	PriorityQueue()
	{
		front = NULL;
		size = 0;
	}
	void insert(int data) {
		queueNode* newNode, * temp;
		newNode = new queueNode;
		newNode->data = data;
		if (front == NULL || data < front->data) {
			newNode->next = front;
			front = newNode;
		}
		else {
			temp = front;
			while (temp->next != NULL && temp->next->data <= data)
				temp = temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
	}
	void del() {
		queueNode* t;
		if (front == NULL)
			cout << "Queue Underflow\n";
		else {
			t = front;
			cout << "Deleted item is: " << t->data << endl;
			front = front->next;
			free(t);
			size--;
		}
	}
	int getSize() {
		return size;
	}
	void show()
	{
		queueNode* ptr;
		ptr = front;
		if (front == NULL)
			cout << "Queue is empty\n";
		else {
			cout << "Queue is :\n";
			cout << "Priority Item\n";
			while (ptr != NULL) {
				cout << ptr->data << endl;
				ptr = ptr->next;
			}
		}
	}
};