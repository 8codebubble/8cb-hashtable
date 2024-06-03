/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashTable.h
 * Author: Yohance McDonald
 *
 * Created on May 11, 2016, 12:16 PM
 */
#include "main.h"
#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;
class HashTable{
private:
    LinkListQueue* array;
    
    
public:
	static const int sizeOfHashtable = 13; // the size of the hash table is better as a prime number
    HashTable();
    int doHash(string strKey);
    void insertNode(string key, int data);
    void removeNode(string key);
    void print(int index);
    
    
};




#endif /* HASHTABLE_H */

