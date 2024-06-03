/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "main.h"

using namespace std;
/* constructor */
HashTable::HashTable(){
    array = new LinkListQueue[this->sizeOfHashtable];
    
}

int HashTable::doHash(string strKey){
    int value = 0;
    for ( int i = 0; i < strKey.length(); i++ )
        value += strKey[i];
    return (value * strKey.length() ) % this->sizeOfHashtable;
}

void HashTable::insertNode(string strKey, int data){	
    int hashIndex = doHash(strKey);
    cout <<""<<hashIndex<<"->"<<"("<<strKey<<"=>"<<data<<")\t";
    QueueNode* node = new QueueNode();
    node->key = strKey;
    node->data = data;
    array[hashIndex].enQueue(node);
}

void HashTable::print(int index)
{
	array[index].printAll();
}
