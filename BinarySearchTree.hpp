//  CS 300 Assignment 4 due 11/21
//  Jena Lovejoy
//  BinarySearchTree.hpp creates a BST and provides functionality like search, delete, and insert

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include <stdio.h>
#include <iostream>
using namespace std;

template <class T>
struct node {
    T data;
    node<T> *left;
    node<T> *right;
    
};

template <class T>
class BinarySearchTree {
private:
    node<T> *root;
    
    void insert(node<T> *&p, T &item){
        
        if (p == NULL){
            node<T> *newNode = new node<T>;
            p = newNode;
            newNode->data = item;
            newNode->left = NULL;
            newNode->right = NULL;
            
            if (root == NULL){
                root = newNode;
            }
            
        } else if (p->data < item){
            insert(p->right, item);
        } else if (p->data > item){
            insert(p->left, item);
        }
    }
    
    int height(node<T> *p){
        if (p == NULL){
            return 0;
        } else {
            return 1 + max(height(p->left), height(p->right));
        }
    }
    
    int max(int x, int y){
        if (x > y){
            return x;
        } else {
            return y;
        }
    }
    
    T& search(node<T> *p, T &item){
        if (p == NULL){
            return item;
            
        } else if (p->data == item){
            return p->data;
            
        } else {
            if (p->data > item){
                return search(p->left, item);
            } else if (p->data < item){
                return search(p->right, item);
            }
        }
        return item;
    }
    
    T findMin(node<T> *p, T &e){
        if (p == NULL){
            return e;
        } else if (p->left != NULL){
            return findMin(p->left);
        } else if (p->left == NULL){
            return p->data;
        }
    }
    
    T findMax(node<T> *p, T &e){
        if (p == NULL){
            return e;
        } else if (p->right != NULL){
            return findMin(p->right);
        } else if (p->right == NULL){
            return p->data;
        }
    }
    
    int count(node<T> *p){
        if (p == NULL){
            return 0;
        } else {
            return 1 + count(p->left) + count(p->right);
        }
    }
    
    void printPreOrder(node<T> *p){
        if (p != NULL){
            cout << p->data << " ";
            printPreOrder(p->left);
            printPreOrder(p->right);
        }
    }
    
    void printPostOrder(node<T> *p){
        if (p != NULL){
            printPostOrder(p->left);
            printPostOrder(p->right);
            cout << p->data << " ";
        }
    }
    
    void printInOrder(node<T> *p){
        if (p != NULL){
            printInOrder(p->left);
            cout << p->data << " ";
            printInOrder(p->right);
        }
    }
    
    void deleteNode(node<T>*& p, T& item){
        if (p == NULL){
            return;
        }
        if (item < p->data){
            deleteNode(p->left, item);
        } else if (item > p->data){
            deleteNode(p->right, item);
        } else {
            if (p->right != NULL && p->left != NULL){
                T maxNode = findMax(p->left, item);
                p->data = maxNode;
                deleteNode(p->left, maxNode);
            } else {
                node<T> *q = p;
                if (p->left != NULL){
                    p = p->left;
                } else if (p->right != NULL){
                    p = p->right;
                } else {

                    p = NULL;
                }
                delete q; 
            }
        }
    }
    
public:
    
    BinarySearchTree(){
        root = NULL;
    }
    
    void insert(T &item){
        insert(root, item);
    }
    
    bool isEmpty(){
        return root == NULL;
        
    }
    
    int height(){
        return height(root);
    }
    
    T& search(T &item){
        return search(root, item);
    }
    
    T findMin(T &e){
        return findMin(root, e);
    }
    
    T findMax(T &e){
        return findMax(root, e);
    }
    
    int count(){
        return count(root);
    }
    
    void printPreOrder(){
        printPreOrder(root);
    }
    
    void printPostOrder(){
        printPostOrder(root);
    }
    
    void printInOrder(){
        printInOrder(root);
    }

    void deleteNode(T& item){
        deleteNode(root, item);
    }
};

#endif /* BinarySearchTree_hpp */
