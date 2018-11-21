//
//  Barcode.hpp
//  ThisAssignment4
//
//  Created by Jena Lovejoy on 11/17/18.
//  Copyright © 2018 Jena Lovejoy. All rights reserved.
//

#ifndef Barcode_hpp
#define Barcode_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Barcode {
protected:
    string UPCCode;
    string info;
    
public:
    Barcode(){
        Barcode("", "");
    }
    
    Barcode(const string &_UPC, const string &_info){
        UPCCode = _UPC;
        info = _info;
    }
    
    ~Barcode(){
    }
    
    Barcode(Barcode &other){
        Barcode(other.UPCCode, other.info);
    }
    
    Barcode& operator=(Barcode &other){
        UPCCode = other.UPCCode;
        info = other.info;
        
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, Barcode &code){
        os << "UPC Code: " << code.UPCCode << endl;
        os << "Info: " << code.info << endl;
        
        return os;
    }
    
    friend bool operator==(const Barcode &A, const Barcode &B){
        return (A.UPCCode).compare(B.UPCCode) == 0;
        // less than, under 0
    }
    friend bool operator!=(const Barcode &A, const Barcode &B){
        return (A.UPCCode).compare(B.UPCCode) != 0;
    }
    friend bool operator>(const Barcode &A, const Barcode &B){
        return (A.UPCCode).compare(B.UPCCode) > 0;
    }
    friend bool operator<(const Barcode &A, const Barcode &B){
        return (A.UPCCode).compare(B.UPCCode) < 0;
    }
    friend bool operator>=(const Barcode &A, const Barcode &B){
        return (A.UPCCode).compare(B.UPCCode) >= 0;
    }
    friend bool operator<=(const Barcode &A, const Barcode &B){
        return (A.UPCCode).compare(B.UPCCode) <= 0;
    }
    
};

#endif /* Barcode_hpp */
