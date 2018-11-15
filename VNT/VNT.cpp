//
//  VNT.cpp
//  VNT
//
//  Created by Maxwell Perry Grossman on 11/15/18.
//  Copyright © 2018 Maxwell Perry Grossman. All rights reserved.
//

#include <iostream>
#include "SafeMatrix.cpp"
using namespace std;


class VNT {
private:
    int m, n;
    SafeMatrix<int> sm;
public:
    // Constructors
    VNT(){
        
    }
    VNT(int, int);
    // Member f(x)
    void add(int);
    int getMin();
    void sort(int[], int);
    bool find(int);
    friend std::ostream& operator<<(std::ostream&, VNT&);
};
