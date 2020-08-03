#include<iostream>
#include"Information_systems.h"
#include"BTS.h"
#include<math.h>
using namespace std;
#include<Windows.h>
BTS binaryTree;
/**
* @brief					: Bu fonksiyon agac yapisina veri ekle isleminin yapilmasini saglar.
*/
void information_systems::add() {
	int adet, value, grade;
	cout << "Adet:";
	cin >> adet;
	for (int i = 0; i < adet; i++)
	{
		cout << i + 1 << ".Student id:";
		cin >> value;
		cout << i + 1 << ".grade:";
		cin >> grade;
		binaryTree.Insert(value, grade);
	}
}
/**
* @brief					: Bu fonksiyon veri silme isleminin yapilmasini saglar.
*/
void information_systems::Delete() {
	int delnum;
	int secim;
	cout << " Enter the number you want to delete.";
	cin >> delnum;
	binaryTree.Delete(binaryTree.root, delnum);
}
/**
* @brief					: Bu fonksiyon veri yapisinin icerdiði toplam eleman sayisi.
*/
void information_systems::Count() {
	cout << binaryTree.leaf(binaryTree.root) << " adet yaprak ve " << binaryTree.totalCount - binaryTree.sameNumber << "adet essiz olmak uzere " << binaryTree.totalCount << " eleman vardir" << endl;
}
/**
* @brief					: Bu fonksiyon verileri ekrana yazdirma isleminin yapilmasini saglar.
*/
void information_systems::Print() {
	binaryTree.display(binaryTree.root, 0);
}

/**
* @brief					: Bu fonksiyon verinin var olup olmadigini bulur.
*/
void information_systems::Find() {
	int fnumber;
	cout << "which number would you like to find.";
	cin >> fnumber;
	if (binaryTree.Find(binaryTree.root, fnumber) == NULL)
	{
		cout << "Number was not found" << endl;
	}
	else
	{
		cout << "This number is in the binarytree." << endl;
	}

}
/**
* @brief					: Bu fonksiyon Listeleme isleminin yapilmasini saglar.
*/
void information_systems::List() {
	int ch;
	cout << "[1]-Preorder" << endl;
	cout << "[2]-Inorder" << endl;
	cout << "[3]-Postorder" << endl;
	cout << "Choose one :";

	cin >> ch;
	if (ch == 1)
	{
		binaryTree.printPreorder(binaryTree.root);
	}
	else if (ch == 2)
	{
		binaryTree.printInorder(binaryTree.root);
	}
	else
	{
		binaryTree.printPostorder(binaryTree.root);
	}
}

/**
* @brief					: Bu fonksiyon verilerin toplama isleminin yapilmasini saglar.
*/
void information_systems::Sum() {

	cout << "Sum =" << binaryTree.sumOfNumbers(binaryTree.root);
}
/**
* @brief					: Bu fonksiyon menu islemlerinin gerceklestirildigi yerdir.
*/
void information_systems::Aort() {
	float Aout;
	cout << "Aritmetic ort =" << (float)binaryTree.sumOfNumbers(binaryTree.root) / binaryTree.totalCount;
}
void information_systems::menu() {
	int selection;
	while (1)
	{
		system("color 3");
		cout << "\n-------------------------------------------" << endl;
		cout << "|                MAIN MENU                |";
		cout << "\n-------------------------------------------" << endl;
		cout << "[1]-Add \n";
		cout << "[2]-Delete\n";
		cout << "[3]-Aritmetic Ort \n";
		cout << "[4]-Show \n";
		cout << "[5]-Find\n";
		cout << "[6]-Count \n";
		cout << "[7]-List " << endl;
		cout << "[8}-Sum" << endl;
		cout << "[9]-Exit" << endl;
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
			int max, min;
			switch (selection)
			{
			case 1:add();
				break;
			case 2:Delete();
				break;
			case 3:Aort();
				break;
			case 4:Print();
				break;
			case 5:	Find();
				break;
			case 6:Count();
				break;
			case 7:List();
				break;
			case 8:Sum();
				break;
			case 9:
				system("pause");
				exit(0);
			}
			cout << endl;
		}
	}
}