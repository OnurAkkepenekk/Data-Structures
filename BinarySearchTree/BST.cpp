#include<iostream>
#include"BTS.h"
#include<iomanip>
using namespace std;
/**
* @brief					: Bu fonksiyon binaryTree constructordir.
*/
BTS::BTS() {

};
/**
* @brief					: Bu fonksiyon binarytreeye veri ekler.
* @param key				: Eklenecek olan tamsayi.
*/
void BTS::Insert(int key, int grade) {

	BinaryTree_Nodes* pp = NULL;
	BinaryTree_Nodes* p = root;
	same_number(p, key, sameNumber);
	totalCount++;
	while (p != NULL)
	{
		pp = p;
		if (key == p->key)
		{
			sum = sum + grade;
			p->counter++;
			return;
		}
		else if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	BinaryTree_Nodes* z = new BinaryTree_Nodes();
	z->key = key;
	z->grade = grade;
	sum = sum + grade;
	z->left = NULL;
	z->right = NULL;
	if (root == NULL)
		root = z;
	else if (key < pp->key)
	{
		pp->left = z;
	}
	else
	{
		pp->right = z;
	}
}
/**
* @brief					: Bu fonksiyon agac yapisindan veri siler.
* @param root				: Eklenme yapilacak olan agac.
* @param deleteKey			: Silinmesi istenen veri numarasi.
*/
BTS::BinaryTree_Nodes* BTS::Delete(BinaryTree_Nodes* root, int deleteKey) {

	if (root == NULL)
	{
		return NULL;
		totalCount--;
	}
	if (deleteKey < root->key)
	{
		root->left = Delete(root->left, deleteKey);
	}
	else if (deleteKey > root->key) {
		root->right = Delete(root->right, deleteKey);
	}
	else
	{
		if (root->left == NULL && root->right == NULL) {
			sum = sum - root->grade;
			if (root->counter == 0)
			{
				free(root);
			}
			(root->counter)--;
			totalCount--;

		}
		else if (root->right == NULL) {
			sum = sum - root->grade;
			if (root->counter == 0)
			{
				BinaryTree_Nodes* temp = root;
				root = root->left;
				free(temp);
			}
			(root->counter)--;
			totalCount--;
		}
		else if (root->left == NULL) {
			sum = sum - root->grade;
			if (root->counter == 0)
			{
				BinaryTree_Nodes* temp = root;
				root = root->right;
				free(temp);
			}
			root->counter--;
			totalCount--;
		}
		else//TWO children
		{
			if (root->counter == 0)
			{
				BinaryTree_Nodes* temp = Min(root->right);
				root->key = temp->key;
				root->right = Delete(root->right, temp->key);
			}
			sum = sum - root->grade;
			root->counter--;
		}
	}
	return root;
}
/**
* @brief					: Bu fonksiyon agac yapisindan aranan verinin olup olmadigini inceler.
* @param root				: Aranacak olan agac.
* @param key				: Aranmasi istenen veri numarasi.
*/
BTS::BinaryTree_Nodes* BTS::Find(BinaryTree_Nodes* root, int key) {
	BinaryTree_Nodes* p = root;
	while (p != NULL) {
		if (key == p->key)
			return p;
		else if (key < p->key)
		{
			p = p->left;
		}
		else
			p = p->right;
	}
}
/**
* @brief					: Bu fonksiyon agac yapisinda yer alan en kucuk elemanin nodesini bulur.
* @param root				: Arama yapilacak olan agac.
*/
BTS::BinaryTree_Nodes* BTS::Min(BinaryTree_Nodes* root) {

	BinaryTree_Nodes* arayici = root;
	while (arayici->left != NULL)
	{
		arayici = arayici->left;
	}
	return arayici;

}

/**
* @brief					: Bu fonksiyon agac yapisindaki verileri preorder olarak yazdirir.
* @param root				: Siralama yapilacak olan agac.
*/
void BTS::printPreorder(BinaryTree_Nodes* root)
{
	if (root == NULL)
		return;
	cout << root->key << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}
/**
* @brief					: Bu fonksiyon agac yapisindaki verileri inorder olarak yazdirir.
* @param root				: Siralama yapilacak olan agac.
*/
void BTS::printInorder(BinaryTree_Nodes* root) {
	if (root == NULL)
		return;
	printInorder(root->left);
	cout << root->key << " ";
	printInorder(root->right);
}
/**
* @brief					: Bu fonksiyon agac yapisindaki verileri postorder olarak yazdirir.
* @param root				: Siralama yapilacak olan agac.
*/
void BTS::printPostorder(BinaryTree_Nodes* root)
{
	if (root == NULL)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->key << " ";
}
/**
* @brief					: Bu fonksiyon agac yapisindaki yer alan ayni verileri tutar.
* @param root				: Arama yapilacak olan agac.
* @param key				: Ayni olma ihtimali olan veri.
* @param same_num			: Ayni olan veri sayisi.
*/
void BTS::same_number(BinaryTree_Nodes* root, int key, int& same_num) {
	if (root != NULL)
	{
		same_number(root->left, key, same_num);
		if (key == root->key)
			same_num++;
		same_number(root->right, key, same_num);
	}
}
/**
* @brief					: Bu fonksiyon agac yapisindaki verileri binaryTree seklinde ekrana bastirir.
* @param root				: Yazdirma yapilacak olan agac.
* @param n					: Ekrana bastirmak icin atilan bosluk sayisi.
*/
void BTS::display(BinaryTree_Nodes* root, int n) {
	if (root != NULL)
	{
		display(root->right, n + 4);
		if (n > 0) {
			cout << setw(n) << " ";
		}
		cout << root->key << endl;
		display(root->left, n + 4);
	}
}
/**
* @brief					: Bu fonksiyon agac yapisindaki yer alan yaprak sayisini yazdirir.
* @param root				: Arama yapilacak olan agac.
*/
int BTS::leaf(BinaryTree_Nodes* root)
{
	int count = 0;
	if (root != NULL)
	{
		if ((root->left == NULL) && (root->right == NULL))
		{
			count = 1;
		}
		else
			count = count + leaf(root->left) + leaf(root->right);
	}
	return count;
}
/**
* @brief					: Bu fonksiyon agac yapisindaki verilerin toplamini hesaplar.
* @param root				: Toplama yapilacak olan agac.
*/
int BTS::sumOfNumbers(BinaryTree_Nodes* root)
{
	return (sum);
}
