/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yohance McDonald
 *
 * Created on May 11, 2016, 12:11 PM
 */

#include "main.h"

using namespace std;

/*
 * 
 */
 
string  gen_random(string s) ;
 
int main(int argc, char** argv) {
    srand (time(NULL));//initialize random seed:
    int randomNumber = -1;
    
    
    HashTable* hashTable = new HashTable();
    string rndStr = "";
    cout <<"Inserting Key=>Data pairs into hash table..."<<endl;
    for(int i=0; i< 10; i++){
        randomNumber = rand() % 100;
        rndStr = gen_random("test");
        hashTable->insertNode(rndStr,randomNumber);
    }
    cout <<endl<<endl;
    cout <<"Print All Hashtable Buckets"<<endl;
    
	for(int j=0; j<hashTable->sizeOfHashtable; j++){
		
		cout <<"("<<j<<")";
		hashTable->print(j);
		cout <<endl;    	
	}
    
    cout <<endl<<"Press ENTER to exit.";
    cin.get();//Hold screen;
            
    return 0;
}

//REF: stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
//modified
string  gen_random(string s) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < s.length(); ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    //s[len] = 0;
    return s;
}


