#include"myStackSLL.h"
#include<iostream>
#include<iomanip>
int numOfMembers = 0;
int spamNum = 0;
using namespace std;
/**
* @brief				: Bu fonksiyon stack constructordir.
* @param top				: Stack yapisinin basini tutar.
* @param stackSize			: Stack boyutu.
*/
Stack::Stack() {
	struct Node* top = NULL;
	stackSize = 5;
}
/**
* @brief				:  Bu fonksiyon stack yapisinin yikici fonksiyonudur (destructor).
*/
Stack::~Stack() {
}
/**
* @brief				: Bu fonksiyon stack yapisine eleman eklenmesini saðlar.
* @param val				: Stack yapisinin basini tutar.
* @param Message			: Gonderilen email.
* @param topic				: Gonderilen emailin mesajin konusu.
* @param spam				: Gonderilen emailin spam durumu.
*/
void Stack::push(int val, string Message, string topic, string spam) {
	struct Node* newnode = new Node();
	newnode->mailNumber = val;
	newnode->message = Message;
	newnode->topic = topic;
	newnode->spam = spam;
	if (spam == "yes" || spam == "YES")
	{
		spamNum++;
	}
	newnode->next = top;
	top = newnode;
	numOfMembers++;
}
/**
* @brief					: Bu fonksiyon stack yapisindaki son elemani siler.
*/
void Stack::pop() {

	struct Node* p = new Node();
	if (top->spam == "yes")
	{
		spamNum--;
	}
	top = top->next;
	numOfMembers--;
}
/**
* @brief				: Bu fonksiyon stack yapisindaki eleman sayisini dondurur.
* @return				: Email kutusundaki eleman sayisi.
*/
int Stack::Count() {
	return numOfMembers;
}
/**
* @brief				: Bu fonksiyon stack yapisindaki spam sayisini dondurur.
* @return				: Email kutusundaki spam sayisi.
*/
int Stack::spamCount() {
	return spamNum;
}
/**
* @brief				: Bu fonksiyon stack yapisinin bos olma durumunu dondurur.
* @return				: True-False.
*/
bool Stack::stackEmpty() {
	return(top == NULL);
}
/**
* @brief				: Bu fonksiyon stack yapisinin dolu olma durumunu dondurur.
* @return				: True-False.
*/
bool Stack::stackFull() {
	return (numOfMembers == stackSize);
}
