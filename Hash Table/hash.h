#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class Hash
{
private:
    static const int tableSize = 40;
    typedef struct item
    {
        string word;
       unsigned long long int index=0;
        int counter=0;
    };

    item HashTable[tableSize];


public:
    int hash(string key);
    Hash();
    int index_kaydýr(int );
    void addItem(string word);
    void searchForWord(string word);
    void topWord(int number);
};

