//
// Created by Mauricio Del Castillo on 11/27/22.
//

#ifndef GVINDEXER_HASHTABLE_H
#define GVINDEXER_HASHTABLE_H

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class HashTable {
    // key hash is name of city,
    // value is pair,
        // first: death counter
        // second: underage death counter
    unordered_map<unsigned int,pair<int,int>> hashTable;

    // list of string with its corresponding hash code
    unordered_map<int,string> decoded;
    vector<string> states = {"Alaska",
                             "Alabama",
                             "Arkansas",
                             "Arizona",
                             "California",
                             "Colorado",
                             "Connecticut",
                             "District of Columbia",
                             "Delaware",
                             "Florida",
                             "Georgia",
                             "Hawaii",
                             "Iowa",
                             "Idaho",
                             "Illinois",
                             "Indiana",
                             "Kansas",
                             "Kentucky",
                             "Louisiana",
                             "Massachusetts",
                             "Maryland",
                             "Maine",
                             "Michigan",
                             "Minnesota",
                             "Missouri",
                             "Mississippi",
                             "Montana",
                             "North Carolina",
                             "North Dakota",
                             "Nebraska",
                             "New Hampshire",
                             "New Jersey",
                             "New Mexico",
                             "Nevada",
                             "New York",
                             "Ohio",
                             "Oklahoma",
                             "Oregon",
                             "Pennsylvania",
                             "Rhode Island",
                             "South Carolina",
                             "South Dakota",
                             "Tennessee",
                             "Texas",
                             "Utah",
                             "Virginia",
                             "Vermont",
                             "Washington",
                             "Wisconsin",
                             "West Virginia",
                             "Wyoming"};

    int numOfCollisions();
public:

    static unsigned int hashFunction(const string& key);
    void insert(const string& key, pair<int,int> value);
    bool search(const string& key);
    int getDeathCount(const string& key);
    int getUnderageCount(const string& key);
    void print();
};


#endif //GVINDEXER_HASHTABLE_H
