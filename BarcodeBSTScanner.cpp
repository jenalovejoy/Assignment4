//  CS 300 Assignment 4 due 11/21
//  Jena Lovejoy
//  BarcodeBSTScanner.cpp builds a Binary Search Tree of Barcodes, given a text file,
//  and then performs search on them and shows the speed of the search

#include "Barcode.hpp"
#include "BinarySearchTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
using namespace std;

const double timeScale = 1000.0 / CLOCKS_PER_SEC; // translates to milliseconds

// Parses the file, building Barcodes and inserting them into the BinarySearchTree
void buildTree(BinarySearchTree<Barcode> &codeTree, string fileName){
    
    ifstream fileStream;
    // stringstream lineStream;
    fileStream.open(fileName);
    string inputString;
    string code;
    string info;

    while (getline(fileStream, inputString)){
        // input string up to new line
        int split = (int) inputString.find(",");
        code = inputString.substr(0, split);
        info = inputString.substr(split + 1);
        
        // Once info is obtained -> build
        Barcode *newBarcode = new Barcode(code, info);
        codeTree.insert(*newBarcode);
    }
}

// Runs tests and calculates the time required for searches within this array
int main(int argc, const char * argv[]) {
    
    const char * fileName = argv[1];

    BinarySearchTree<Barcode> codeTree;
    buildTree(codeTree, fileName);
    
    string exampleCodes[] = {"8717644525098", "71000", "459136", "41570059012", "60410047613", "00000", "725177540363"};
    // Item numbers 680, 76407, 660896, 67170, 1035244, non-existant, and 1
    
    int iterations = 100;
    int numExamples = 7;
    clock_t timeSum = 0;
    
    // Outside loop tests the example code cases 100 times, then finds the average length of the searches performed
    // Inside success cout statements kept as an additional option in testing
    for (int i = 0; i < iterations; i++){
    
        // For each example, run the test and keep how long it took
        for (string code : exampleCodes){
            Barcode *searchCode = new Barcode(code, "");
            clock_t start;
            clock_t finalTime;
            
            start = clock();
            Barcode *result(&codeTree.search(*searchCode));
            finalTime = clock() - start;
            
            if (searchCode != result){
                // cout << "Item found: \n" << *result;
            } else {
                // cout << "Item not found: ";
            }
            timeSum += finalTime;
        }
   }
        
        double average = ((double) timeSum / (numExamples * iterations)) * timeScale;
        
        cout << "average search time: " << average << " milliseconds." << endl;
}



