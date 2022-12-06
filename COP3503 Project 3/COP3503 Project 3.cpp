#include <SFML/Graphics.hpp>
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include "nAry.h"

using namespace std;


nAry* SetData(nAry* root, int gunViolence, int underagedDeaths, string state, queue<nAry*>& trackPos) {
    
    /*if (trackPos.empty()) {
        return nullptr;
    }*/ //Dont use this if statement because it stops function from iterating; needs to be placed somewhere else though

    if (root == nullptr) {
        root = new nAry(gunViolence, underagedDeaths, state); 
        for (int i = 0; i < 5; i++) {
            root->children[i] = new nAry();
            trackPos.push(root->children[i]);
        }
    }
    else {
        trackPos.front() = new nAry(gunViolence, underagedDeaths, state);
        for (int i = 0; i < 5; i++) {
            trackPos.front()->children[i] = new nAry();
            trackPos.push(trackPos.front()->children[i]);
        }
        trackPos.pop();
    }

    

    /*if (root->children.size() != 5) {
        root->children.push_back(new nAry(gunViolence, underagedDeaths, state));
    }
    else {
        SetData(root->trackPos.front(), gunViolence, underagedDeaths, state);
        root->trackPos.pop();
    }*/

    return root;
}

//Prints nAry tree
void SearchData(nAry* head) {

    queue<nAry*> q;
    q.push(head);


    while (!q.empty()) {

        if (q.front() == nullptr) {
            q.pop();
            break;
        }

        cout << q.front()->state << " ";
        cout << q.front()->gunViolence << " ";
        cout << q.front()->underagedDeaths << " ";

        for (int i = 0; i < 5; i++) q.push(q.front()->children[i]);

        q.pop();

    }

}

int main()
{
    HashTable ht;
    queue<nAry*> trackPos;

    //Create n-ary instance
    nAry* root = nullptr;

    //Open file
    fstream fin;
    fin.open("Test Data.csv");

    //Declare string inputs
    string row, word;
    string state;
    int underageDeaths, gunViolence;
    vector<string> ages;

    getline(fin, row);
    //While program can input rows of data
    while (getline(fin, row)) {
        underageDeaths = 0;
        ages.clear();
        
        //Associate string object with stream
        stringstream s(row);

        //Stores state
        getline(s, word, ',');
        state = word;
        //cout << state << endl;

        //Stores fatalities
        getline(s, word, ',');
        gunViolence = stoi(word);
        //cout << gunViolence << endl;

        //Stores ages of those involved 
        getline(s, word, ',');
        string str = word;
        string delimiter = "||";
        size_t pos = 0;
        string token;
        while ((pos = str.find(delimiter)) != std::string::npos) {
            token = str.substr(0, pos);
            //std::cout << token << std::endl;
            ages.push_back(token);
            str.erase(0, pos + delimiter.length());
        }
        //std::cout << str << std::endl;
        ages.push_back(str);
        

        //Stores which of those involved were killed/injured
        getline(s, word, ',');
        str = word;
        delimiter = "||";
        pos = 0;
        int count = 0;
        int ageSize = ages.size();
        while ((pos = str.find(delimiter)) != std::string::npos) {
            token = str.substr(0, pos);
            
            if ((count < ageSize) && (ages[count].find("Teen") != string::npos || ages[count].find("Child") != string::npos) 
                && (token.find("Killed") != string::npos))
                    underageDeaths++;

            count++;
            //std::cout << token << std::endl;
            str.erase(0, pos + delimiter.length());
        }
        //std::cout << str << std::endl;
        if ((ages[ageSize - 1].find("Teen") != string::npos || ages[ageSize - 1].find("Child") != string::npos) && 
            (str.find("Killed") != string::npos))
            underageDeaths++;
        

        //cout << underageDeaths << endl;

        //Inserts a node into nAry tree
        root = SetData(root, gunViolence, underageDeaths, state, trackPos);

        // HASHTABLE INSERT
        pair<int,int> value(gunViolence, underageDeaths);
        ht.insert(state, value);

    }

    
    ht.print();
    //SearchData(root);

    //cout << root->children[0]->gunViolence;
    


    return 0;
}