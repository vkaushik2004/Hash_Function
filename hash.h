#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

class HashTable {
    private:
        struct Node{
            std::string data;
            Node* next;
        };

    int size;
    Node** table;

    int hash_function(const std::string& key);

    public:
        HashTable(int tableSize);
        ~HashTable();

        void insert(const std::string& key);
        void printTable();
        int getSlotLength(int slot);
        double getVariance();
};

#endif
