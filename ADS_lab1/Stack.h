#include <stdio.h>
#include <iostream>

using namespace std;

class Stack
{
public:
	/*
	Puts given item on the top of a stack.
	Returns 0 if no error occured and 1 otherwise (e.g. lack of memory).
	*/
	 virtual int push(int) abstract;

	 /*
	 Gets top element of the stack and removes it from the stack.	 
	 Element is stored using a pointer argument. If argument is null,
	 the element is removed without storing its value.
	 Returns 0 if no error occured and 1 otherwise (e.g. stack is empty).
	 */
	 virtual int pop(int* item = NULL) abstract;

	 /*
	Gets the top element of the stack (without removing it) using pointer argument.
	Returns 0 if no error occured and 1 otherwise (e.g. stack is empty).
	*/
	 virtual int top(int*) abstract;

	 	/*
	Removes all the elements from the stack.
	*/
	 virtual void clear() abstract;

	 	/*
	Returns the number of items in the stack.
	*/
	 virtual int getCount() abstract;

	 	/*	
	Returns true if the stack is empty and false otherwise.
	*/
	 virtual bool isEmpty() abstract;	

	 	/*
	Prints current items in the stack starting from the top.
	*/
	 virtual void print() abstract;
};