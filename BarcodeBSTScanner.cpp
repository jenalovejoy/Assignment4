//  CS 300 Assignment 4 due 11/20
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

const double timeScale = 1000.0 / CLOCKS_PER_SEC; // in milliseconds

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

void runExamples(BinarySearchTree<Barcode> &codeTree, const string &code){
    
    Barcode *searchCode = new Barcode(code, "");
    clock_t start;
    clock_t finalTime;
    
    start = clock();
    Barcode result = codeTree.search(*searchCode);
    finalTime = clock() - start;
    
    cout << result << endl;
    cout << "This took " << (double) finalTime * timeScale << " milliseconds." << endl;
    
}


int main(int argc, const char * argv[]) {
    
    const char * fileName = argv[1];
    
    // string fileName = "/Users/jena/Desktop/CorpusSmall.txt";
    // string fileName = "/Users/jena/Desktop/CorpusFull.txt";
    
    BinarySearchTree<Barcode> codeTree;
    buildTree(codeTree, fileName);
    
    cout << "tree built" << endl;
    
    cout << "height = " << codeTree.height() << endl;
    
    runExamples(codeTree, "799000052"); // 16 oz Trader Joe's Raw Almonds
    runExamples(codeTree, "300000663"); // Trader Joe's
    runExamples(codeTree, "71000"); // 6 OZ Trader Joe's Just Mango Slices
    runExamples(codeTree, "459136"); // 1.8 OZ 5G CURRY POWDER -TRADER JOE'S
    runExamples(codeTree, "41570059012"); // Blue Diamond Almonds - Bold Salt 'n Vinegar Flavor
    runExamples(codeTree, "60410047613"); // Tostitos Hint Of Lime
    
    
}

