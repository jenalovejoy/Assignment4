//  CS 300 Assignment 4 due 11/20
//  Jena Lovejoy
//  BarcodeArrayScanner.cpp builds an array of Barcodes, given a text file,
//  and then performs search on them and shows the speed of the search

#include "Barcode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
using namespace std;

const double timeScale = 1000.0 / CLOCKS_PER_SEC; // in milliseconds

// returns capacity
int buildArray(Barcode *codeArray[], const char * fileName){ // string fileName
    
    ifstream fileStream;
    fileStream.open(fileName);
    string inputString;
    string code;
    string info;
    int index = 0;
    
    while (getline(fileStream, inputString)){
        // input string up to new line
        int split = (int) inputString.find(",");
        code = inputString.substr(0, split);
        info = inputString.substr(split + 1);
        
        // Once info is obtained -> build
        Barcode *newBarcode = new Barcode(code, info);
        codeArray[index] = newBarcode;
        index++;
    }
    
    return index - 1;
}

Barcode& search(Barcode *codeArray, int size, Barcode &code){
    
    for (int i = 0; i <= size; i++){
        if (codeArray[i] == code) {
            return codeArray[i];
        }
    }
    return code;
}

void runExamples(Barcode *codeArray, int size, const string &code){
    
    Barcode searchCode(code, "");
    clock_t start;
    clock_t finalTime;
    
    start = clock();
    search(codeArray, size, searchCode);
    finalTime = clock() - start;
    
    cout << "This took " << (double) finalTime * timeScale << " milliseconds." << endl;
}
/*
int main(int argc, const char * argv[]) {
 
    const char * fileName = argv[1];
    Barcode *codeArray = new Barcode[1050000];
  
    int size = buildArray(&codeArray, fileName);

    runExamples(codeArray, size, "799000052"); // 16 oz Trader Joe's Raw Almonds
    runExamples(codeArray, size, "300000663"); // Trader Joe's
    runExamples(codeArray, size, "71000"); // 6 OZ Trader Joe's Just Mango Slices
    runExamples(codeArray, size, "459136"); // 1.8 OZ 5G CURRY POWDER -TRADER JOE'S
    runExamples(codeArray, size, "41570059012"); // Blue Diamond Almonds - Bold Salt 'n Vinegar Flavor
    runExamples(codeArray, size, "60410047613"); // Tostitos Hint Of Lime
   
}

*/
