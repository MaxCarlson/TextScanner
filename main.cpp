/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: C-60
 *
 * Created on May 15, 2017, 8:41 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <valarray>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //input file name
    string tmp;
    cout << "Please enter file name(in same directory as .exe)" << endl;
    cin >> tmp;
    
    //input string/char to search
    cout << "Enter string you'd like to search for" << endl;
    string characters;
    cin >> characters;
    
    ifstream file;
    file.open(tmp.c_str());
    
    if(file == NULL){
        cout << "Error with file" << endl;
        exit(0);
    } 
     
    int numberT = 0, wordCount = 0, characterCount = 0;
    
    string word;
    while(file >> word){ 
        wordCount ++;
        size_t pos {0};
        characterCount += word.size();
        
        size_t found = word.find(characters);
        if(found != string::npos){ //If there is one occurrence of entered string count it and try to find more
            for(;;){
                pos = word.find(characters,pos);
                if(pos == string::npos){
                    break;      //break if rest of string contains no matches
                }
                ++ pos;
                ++ numberT;        
            }
        }
        
    }
    //double percCh = (double) 100*(numberT/characterCount);
    
    cout << "Number of times this string occurred: " << numberT << endl;
    cout << "Total Number of words: " << wordCount << endl;
    //cout << "Percentage string occurance in number of characters: " << percCh << endl;
    
    

    return 0;
}

