#pragma once
#include<iostream>
class BTS
{
private:

public:
	struct BinaryTree_Nodes {
		int key;
		int grade;
		BinaryTree_Nodes* left;
		BinaryTree_Nodes* right;
		int counter = 0;
	};
	BTS();
	int sameNumber;
	int totalCount;
	int sum;
	BinaryTree_Nodes* root;
	BinaryTree_Nodes* root1;
	void Insert(int key,int grade);
	BinaryTree_Nodes* Find(BinaryTree_Nodes *root,int key);
	BinaryTree_Nodes* Min(BinaryTree_Nodes* root);
	void printPreorder(BinaryTree_Nodes* root);
	void printInorder(BinaryTree_Nodes* root);
	void printPostorder(BinaryTree_Nodes* root);
	void same_number(BinaryTree_Nodes* root,int key,int &samenum);
	int leaf(BinaryTree_Nodes* root);
	int sumOfNumbers(BinaryTree_Nodes* root);
	void display(BinaryTree_Nodes* agac, int indent);
	BinaryTree_Nodes* Delete(BinaryTree_Nodes* agac, int silinecekdeger);
};