# Data Structures: Assignment 4

The main files of this program are BinarySearchTree.hpp, BarcodeBSTScanner.cpp, BarcodeArrayScanner.cpp, and Barcode.hpp.

Also included are 6 text files: these are the data set which can be loaded individually into the program. 
They're all the same set, just increasing sizes where Corpus10Item is the first 10 items of Corpus1MItem, 
Corpus100Item is the first 100 items of Corpus1MItem, and so on. 

## Assignment details
In this assignment, you are asked to design and develop a C++ program that allow users to quickly look up items by their UPC Code. The Universal Product Code (UPC) is a barcode symbology that is widely used in the United States, Canada, United Kingdom, Australia, New Zealand, in Europe and other countries for tracking trade items in stores. UPC consists of numeric digits, that are uniquely assigned to each trade item.
You can think that your application could be running on a device connected to bar code scanner or behind a web or mobile application that reads UPC codes as user input.
You are provided with a large dataset of UPC codes (more than 1billion) for all kinds of things.

### Requirements:
• Provide implementation for Binary Search Tree header file
• Write a barcode scanner client program that reads in the provided data file into a binary
search tree object, use UPC code as the key and name your program as BarcodeBSTScanner.cpp. For simplicity, you can just read the UPC code (the number that appears before the first comma) into one field (use the UPC code as the “key”) and then read the remaining info into a single string (the “value” associated with the key). You may assume that there will be no duplicate keys in data sets.
• Write a separate barcode scanner client program that uses arrays instead of binary search tree (BarcodeArrayScanner.cpp)
• Perform several experiments on various data set sizes to examine the performance of search operation in both binary search tree-based and array-based solutions. Keep timing for experiments and draw a graph to compare the results of the performances of both implementations.
