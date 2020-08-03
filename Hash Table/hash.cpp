#include "hash.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
Hash::Hash()
{		//Constructor creates initial table and reads in file info

	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i].word = "empty";
		HashTable[i].counter = 0;
	}
	ifstream inFile("b.txt");
	string word;
	int counter = 0;
	while (!inFile.eof())
	{
		inFile >> word;
		addItem(word);
	}
}

int Hash::hash(string key)
{		//Hash function decides which bucket to place item 
	unsigned long long int hashCode = 0;
	int index;
	for (int i = 0; i < key.length(); i++)
	{
		hashCode = (hashCode << 5) + key[i] - 'a';
	}

	index = hashCode % tableSize;
	return index;
}
int Hash::index_kaydýr(int tutucu) {

	if (HashTable[tutucu].word != "empty")
	{
		tutucu++;
		if (tutucu > tableSize)
		{
			tutucu = 0;
		}
		index_kaydýr(tutucu);
	}
	return tutucu;
}

void Hash::addItem(string word)
{		//Function manually adds item to the tree
	int tutucu = hash(word);

	if (HashTable[tutucu].word == "empty")
	{
		HashTable[tutucu].index = tutucu;
		HashTable[tutucu].word = word;
		HashTable[tutucu].counter++;
	}
	else
	{
		if (HashTable[tutucu].word != word)
		{
			tutucu = index_kaydýr(tutucu);
			HashTable[tutucu].index = tutucu;
			HashTable[tutucu].word = word;
			HashTable[tutucu].counter++;
		}
		else
		{
			HashTable[tutucu].counter++;
		}
	}
	cout << HashTable[tutucu].index << " kelime =" << HashTable[tutucu].word << " Kelime sayisi :" << HashTable[tutucu].counter << endl;
}
void Hash::searchForWord(string word) {
	int counter = 0;
	for (int i = 0; i < tableSize; i++)
	{
		if (word == HashTable[i].word)
		{
			cout << HashTable[i].word << " " << HashTable[i].counter;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "Kelime bulunamamistir..." << endl;
	}
}
void Hash::topWord(int number) {
	int dizi[tableSize];
	int max = 0;
	for (int i = 0; i < tableSize - 1; i++)
	{
		for (int j = 0; j < tableSize - 1 - i; j++)
		{
			if (HashTable[j].counter < HashTable[j + 1].counter)
			{
				swap(HashTable[j + 1], HashTable[j]);
			}
		}
	}
	for (int i = 0; i < number; i++)
	{
		cout << HashTable[i].counter << HashTable[i].word << endl;
	}
}