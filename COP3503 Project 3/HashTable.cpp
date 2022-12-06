//
// Created by Mauricio Del Castillo on 11/27/22.
//

#include "HashTable.h"
#include <iostream>
#include <map>
using namespace std;
unsigned int HashTable::hashFunction(const string &key) {
    unsigned int sum = 0;
    for(char i : key){
        sum += tolower(i);
    }
    return sum;
}

void HashTable::insert(const string& key, pair<int, int> value) {
    unsigned int hashCode = hashFunction(key);
    decoded[hashCode] = key;
    this->hashTable[hashCode].first += value.first;
    this->hashTable[hashCode].second += value.second;
}

int HashTable::numOfCollisions() {
    map<unsigned int, int> temp;
    int cnt = 0;
    for(auto & state : this->states){
        unsigned int hashCode = hashFunction(state);
        temp[hashCode]++;
        if(temp[hashCode] > 1){
            cnt++;
            cout <<"COLLISION with state: " << state << endl;
        }
    }
    cout <<"Number of keys: " <<temp.size()<< endl;
    return cnt;
}

bool HashTable::search(const string &key) {
    unsigned int hashCode = hashFunction(key);
    if(this->hashTable.find(hashCode) != this->hashTable.end()){
        return true;
    }
    return false;
}

int HashTable::getDeathCount(const string &key){
    unsigned int hashCode = hashFunction(key);
    return this->hashTable[hashCode].first;
}

int HashTable::getUnderageCount(const string &key){
    unsigned int hashCode = hashFunction(key);
    return this->hashTable[hashCode].second;
}

void HashTable::print() {
    unordered_map<unsigned int,pair<int,int>>::iterator it;
    for(it=this->hashTable.begin(); it!=this->hashTable.end(); it++){
        cout << "State: " << decoded[it->first] << " | Deaths: " << it->second.first << " | Underage Deaths: " << it->second.second << endl;
    }
}