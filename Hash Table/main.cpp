#include<iostream>
#include"hash.h"
#include<fstream>
using namespace std;
int main() {
	int choice;
	Hash hashObj;
	hashObj.topWord(8);
	do
	{		//Loop for switch case interface
		cout << "Would you like to search for a word? (1)yes or (0)no: ";
		cin >> choice;
		string search;

		switch (choice)
		{

		case 0:
			cout << "Exiting" << endl;
			break;

		case 1:
		{
			string search;
			cout << "Enter the word you wish to search for: \n";
			cin >> search;
			hashObj.searchForWord(search); //Finds word entered by the user
			cout << endl;
			break;
		}
		default:
			cout << "Try Again." << endl;
		}
	} while (choice != 0);


	system("pause");
}