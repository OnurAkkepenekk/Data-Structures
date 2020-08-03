#include"myStackSLL.h"
#include"mailBox.h"
#include<iomanip>
#include<string>
#include<Windows.h>
using namespace std;
Stack primary;
Stack S;
Stack Starred;
Stack S1;
int starredNum = 0;
/**
* @brief					: Bu fonksiyon gelen kutusuna email ekleme islemi yapar.
*/
void mailBox::add() {
	int addNumMail, num;
	string message, topic, spam;
	if (primary.stackFull())
	{
		cout << "Inbox is full" << endl;
	}
	else
	{
		cout << "The number of emails you want to add.:" << endl;
		cin >> addNumMail;
		for (int i = 0; i < addNumMail; i++)
		{
			cout << "Email Number: ";
			cin >> num;
			cout << "Topic: ";
			cin.ignore();
			getline(cin, topic);
			cout << "Message: ";
			getline(cin, message);
			cout << "Spam or not spam ? [yes]-[no]";
			getline(cin, spam);
			primary.push(num, message, topic, spam);
		}
	}
}
/**
* @brief					: Bu fonksiyon email gosterimi yapar ve gosterilmis olan bilgileri stackten cikarir.
*/
void mailBox::pop()
{
	if (primary.stackEmpty()) {
		cout << "Email box is empty." << endl;
	}
	else {
		S = primary;
		cout << left << setw(35) << "**Massage**" << endl;
		cout << S.top->message;
		primary.pop();
	}
}
/**
* @brief					: Bu fonksiyon stack yapisindaki elemanlari tarayarak girilen numarali emaili bulur ve ekrana yazdirir.
*/
void mailBox::searchMail() {
	int count, number, control = 0, location = 0;
	count = primary.Count();
	S.top = primary.top;
	cout << "Number of mail:";
	cin >> number;
	for (int i = 0; i < count; i++)
	{
		location++;
		if (S.top->mailNumber == number)
		{
			control++;
			cout << "This e-mail location is :" << location << endl;
			cout << left << setw(35) << "Number Of Email";
			cout << left << setw(35) << "Company Name";
			cout << left << setw(35) << "TOPIC";
			cout << left << setw(35) << "Spam Status";
			cout << endl;
			cout << left << setw(35) << "-------------";
			cout << left << setw(35) << "-------------";
			cout << left << setw(35) << "-------------";
			cout << left << setw(35) << "-------------";
			cout << endl;
			cout << left << setw(35) << S.top->mailNumber;
			cout << left << setw(35) << S.top->message;
			cout << left << setw(35) << S.top->topic;
			cout << left << setw(35) << S.top->spam;
			break;
		}
		S.top = S.top->next;
	}
	if (control == 0) {
		cout << "Email number " << number << " could not be found." << endl;
	}
}
/**
* @brief					: Bu fonksiyon mail kutusundaki postalari ekrana yazdirir.
*/
void mailBox::showEmails()
{
	if (primary.stackEmpty())
	{
		cout << "Inbox empty" << endl;
	}
	else
	{
		int count = primary.Count();
		S.top = primary.top;
		while (S.top != NULL)
		{
			cout << left << setw(35) << "Number Of Email";
			cout << left << setw(35) << "TOPIC";
			cout << left << setw(35) << "Message";
			cout << left << setw(35) << "Spam Status";
			cout << endl;
			cout << left << setw(35) << "-------------";
			cout << left << setw(35) << "-------------";
			cout << left << setw(35) << "-------------";
			cout << left << setw(35) << "-------------";
			cout << endl;
			for (int i = 0; i < count; i++)
			{
				cout << left << setw(35) << S.top->mailNumber;
				cout << left << setw(35) << S.top->topic;
				cout << left << setw(35) << S.top->message;
				cout << left << setw(35) << S.top->spam;
				S.top = S.top->next;
				cout << endl;
			}
		}
	}
}
/**
* @brief					: Bu fonksiyon gelen kutusundaki okunmamis emaillerin sayisini yazdirir.
*/
void mailBox::emailNumber()
{
	int count;
	count = primary.Count();
	cout << "Number of e-mails :" << count;
}
/**
* @brief					: Bu fonksiyon gelen kutusunda yer alan spam maillerinin sayisini yazdirir.
*/
void mailBox::spamNumber() {
	int spamNumber = primary.spamCount();
	cout << "Number of Spam :" << spamNumber;
}
/**
* @brief					: Bu fonksiyon gelen kutusundaki secilmis olan mailleri yildizli maillere ekler.
*/
void mailBox::starredMail() {
	int number, counter, findstatus = 0;
	S1.top = primary.top;
	counter = primary.Count();
	cout << "Number of mail:";
	cin >> number;
	for (int i = 0; i < counter; i++)
	{
		if (S1.top->mailNumber == number)
		{
			Starred.top = S1.top;
			starredNum++;
			findstatus++;
		}
		S1.top = S1.top->next;
	}
	if (findstatus == 0)
	{
		cout << "This mail could not be found at Inbox !!!" << endl;
	}
	else
	{
		cout << endl;
		cout << "This mail has been starred at Starred Inbox ";
	}
}
/**
* @brief					: Bu fonksiyon yildizli mailleri ekrana yazdirir.
*/
void mailBox::printStarttedMail() {
	if (Starred.top == NULL) {
		cout << "Starred inbox empty " << endl;
	}
	else
	{
		cout << endl;
		cout << right << setw(70) << " ********************* STARRED MAILS ********************* " << endl;
		cout << left << setw(35) << "Number Of Email";
		cout << left << setw(35) << "Topic";
		cout << left << setw(35) << "Message";
		cout << left << setw(35) << "Spam Status";
		cout << endl;
		cout << left << setw(35) << "-------------";
		cout << left << setw(35) << "-------------";
		cout << left << setw(35) << "-------------";
		cout << left << setw(35) << "-------------";
		cout << endl;
		for (int i = 0; i < starredNum; i++)
		{
			if (Starred.stackEmpty())
			{
				cout << "Inbox is empty." << endl;
			}
			else {

				cout << left << setw(35) << Starred.top->mailNumber;
				cout << left << setw(35) << Starred.top->topic;
				cout << left << setw(35) << Starred.top->message;
				cout << left << setw(35) << Starred.top->spam;
				cout << endl;
				Starred.top = Starred.top->next;
			}
		}
	}
}
/**
* @brief					: Bu fonksiyonda menu islemleri yapilir.
*/
int mailBox::Menu() {
	int selection;

	while (1)
	{
		system("color 3");
		cout << "\n-------------------------------------------" << endl;
		cout << "|                MAIN MENU                |";
		cout << "\n-------------------------------------------" << endl;
		cout << "[1]-Send an e-mail \n";
		cout << "[2]-Show last e-mail\n";
		cout << "[3]-List e-mails \n";
		cout << "[4]-Number of e-mail \n";
		cout << "[5]-Number of spam \n";
		cout << "[6]-E-mail search by number\n";
		cout << "[7]-Make starred  mails \n";
		cout << "[8]-Show starred mails" << endl;
		cout << "[9}-Exit" << endl;
		cout << "\n Please select: ";
		cin >> selection;
		if (cin.fail())
		{
			cout << "You made an incorrect entry.Try again";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else if (selection < 0 || selection > 9)
		{
			cout << "You made an incorrect entry.Try again";
			Sleep(999);
			cin.clear();
			cin.ignore(10, '\n');
			system("cls");
		}
		else
		{
			system("cls");
			string name, konu;
			switch (selection)
			{
			case 1:
				add();
				break;
			case 2:
				pop();
				break;
			case 3:
				showEmails();
				break;
			case 4:
				emailNumber();
				break;
			case 5:
				spamNumber();
				break;
			case 6:
				searchMail();
				break;
			case 7:starredMail();
				break;
			case 8:printStarttedMail();
				break;
			case 9:
				system("pause");
				exit(0);
			}
			cout << endl;
		}
	}
}