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
    
    string tmp;
    cout << "Please enter file name(in same directory as .exe)" << endl;
    cin >> tmp;
    
    //create file object, read file object, check if null
    //FILE* pFile;
    //pFile = fopen(tmp.c_str(), "r");
    
    cout << "Enter string you'd like to search for" << endl;
    string characters;
    cin >> characters;
    
    ifstream file;
    file.open(tmp.c_str());
    
    if(file == NULL){
        cout << "Error with file" << endl;
        exit(0);
    } 
    
    
    int numberT = 0, wordCount = 0;
    //size_t pos{0};
    
    string word;
    while(file >> word){
        wordCount ++;
        size_t pos {0};
        //size_t found = word.find(characters);
        //if(found != string::npos){
        //    numberT++;
        //}
        size_t found = word.find(characters);
        if(found != string::npos){
            for(;;){
                pos = word.find(characters,pos);
                if(pos == string::npos){
                    break;
                }
                ++ pos;
                ++ numberT;        
            }
        }
        
    }
    
    cout << numberT << endl;
    
    
    

    return 0;
}

