#pragma once
#include<iostream>
#include"mailBox.h"
using namespace std;
class Stack
{
	friend class mailBox;
public:
	Stack();
	~Stack();
	void push(int val, string name, string topic, string spam);
	void pop();
	int Count();
	bool stackEmpty();
	bool stackFull();
	int spamCount();
private:
	int stackSize;
	struct Node {
		int mailNumber;
		string message;
		string topic;
		string spam;
		struct Node* next;
	};
	struct Node* top = NULL;
};
