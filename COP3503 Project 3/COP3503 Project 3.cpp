#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "nAry.h"

using namespace std;



int main()
{
    //Create n-ary instance
    nAry* node = new nAry;

    //Open file
    fstream fin;
    fin.open("Gun Violence Data.csv");

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
        cout << state << endl;

        //Stores fatalities
        getline(s, word, ',');
        gunViolence = stoi(word);
        cout << gunViolence << endl;

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
        

        cout << underageDeaths << endl;


        node->SetData(gunViolence, underageDeaths, state);

        //cout << underageDeaths << endl;
        //While program can input words from 
        //previously inputted row of data
        //while (getline(s, word, ',')) {
            //count++;
            //for (int i = 0; i < 29; i++) {
            //    getline(s, word, ',');
            //    if (i == 2) {
            //        state = word;
            //    }
            //    if (i == 5) {
            //        gunViolence = word;
            //    }
            //    if (i == 18) {
            //        std::string s = word;
            //        std::string delimiter1 = "||";
            //        size_t pos = 0;
            //        std::string token;
            //        while ((pos = s.find(delimiter1)) != std::string::npos) {
            //            token = s.substr(0, pos);
            //            //token = token.substr(3);
            //            std::cout << token << std::endl;
            //            s.erase(0, pos + delimiter1.length());
            //        }
            //        //s = s.substr(3);
            //        std::cout << s << std::endl;
            //        cout << state << " " << gunViolence << endl;
            //    }
            //}
            //data.push_back()
            
            
            /*temp = word;
            cout << word << endl;
            getline(s, word, ',');
            temp = word;
            cout << word << endl;
            getline(s, word, ',');
            state = word;
            cout << word << endl;*/

        //}
    }


}