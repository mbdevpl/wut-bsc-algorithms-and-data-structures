#include "ListStack.h"


ListStack::ListStack() {
	head = NULL;
	count = 0;
}

ListStack::~ListStack() {
	clear();
}

int ListStack::push(int val) {
	int newcount = count + 1;
	if (newcount < count) return 1; //overflow
	node* temp = head;
	head = new node;
	if (head == NULL) return 1;
	head->value = val;
	head->next = temp;
	count++;
	return 0;
}

int ListStack::pop(int* elem) {
	if (count <= 0) return 1;
	if (head == NULL) return 1;
	if (elem != NULL) *elem = head->value;
	node* temp = head;
	head = head->next;
	delete temp;
	count--;
	return 0;
}

int ListStack::getCount() {
	return count;
}

int ListStack::top(int* elem) {
	if (count <= 0) return 1;
	if (head == NULL) return 1;
	if (elem != NULL) *elem = head->value;
	return 0;
}

void ListStack::clear() {
	for (int i = 0; i<count; i++) {
		node* temp = head;
		head = head->next;
		delete temp;
	}
	count = 0;
	head = NULL;
}

bool ListStack::isEmpty() {
	return (count == 0);
}

void ListStack::print() {
	if (count > 0) cout << "Contents: ";
	else cout << "Stack is empty.\n";
	for (node* temp = head; temp != NULL; temp = temp->next) {
		cout << temp->value << (temp->next == NULL? "\n" : ",");
	}
}
