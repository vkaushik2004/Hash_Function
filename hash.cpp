#include "hash.h"
#include <iostream>
#include <cstddef> // For NULL definition
#include <cmath> // For sqrt

HashTable::HashTable(int tableSize) {
    size = tableSize;
    table = new Node*[size];
    for (int i = 0; i < size; ++i)
        table[i] = NULL;
}

HashTable::~HashTable() {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

int HashTable::hash_function(const std::string& key) {
    int hash = 0;
    for (size_t i = 0; i < key.length(); ++i) {
        hash += key[i];
    }
    return hash % size;
}

void HashTable::insert(const std::string& key) {
    int index = hash_function(key);
    Node* newNode = new Node;
    newNode->data = key;
    newNode->next = NULL;

    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void HashTable::printTable() {
    for (int i = 0; i < size; ++i) {
        std::cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current != NULL) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
}

int HashTable::getSlotLength(int slot) {
    int length = 0;
    Node* current = table[slot];
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

double HashTable::getVariance() {
    double mean = 0;
    double sumSquaredDifferences = 0;

    for (int i = 0; i < size; ++i) {
        mean += getSlotLength(i);
    }
    mean /= size;

    for (int i = 0; i < size; ++i) {
        double diff = getSlotLength(i) - mean;
        sumSquaredDifferences += diff * diff;
    }

    double variance = sumSquaredDifferences / size;

    return sqrt(variance);
}
