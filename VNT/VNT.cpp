//
//  VNT.cpp
//  VNT
//
//  Created by Maxwell Perry Grossman on 11/15/18.
//  Copyright © 2018 Maxwell Perry Grossman. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "SafeMatrix.cpp"
using namespace std;


class VNT {
private:
    int height, width;
    SafeMatrix<int> matrix;
public:
    
    // default constructor
    VNT(){
        height=0;
        width=0;
        matrix = SafeMatrix<int>();
        
    }
    
    //two parameter constructor
    VNT(int h, int w){
        height=h;
        width=w;
        matrix=SafeMatrix<int>(h,w);
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                matrix[i][j] = INT_MAX;
    }
    
    //add a value to the VNT
    void add(int value){
        if (matrix[height - 1][width - 1] < INT_MAX) {
            cout << "VNT is Full" << endl;
            return;
        }
        matrix[height - 1][width - 1] = value;
        
        int r = height - 1;
        int c = width - 1;
        
        while (r > 0) {
            c = width - 1;
            /* If the cell on top of our value contains a
             bigger value, swap values */
            if (matrix[r - 1][c] > matrix[r][c])
                swap(matrix[r - 1][c], matrix[r][c]);
            while (c > 0) {
                /* If the value is at the most upper rightmost corner
                 and the cell to its left has a greater value */
                if (r == 1 && (matrix[r - 1][c - 1] > matrix[r - 1][c])) {
                    // Swap value with the cell to its left
                    swap(matrix[r - 1][c - 1], matrix[r - 1][c]);
                    // Swap cell below our value with the cell to its left
                    swap(matrix[r][c - 1], matrix[r][c]);
                }
                else if (matrix[r][c - 1] > matrix[r][c]) {
                    // Swap cell below our value with the cell to its left
                    swap(matrix[r][c - 1], matrix[r][c]);
                }
                c--;
            }
            r--;
        }
    }
    
    int getMin(){
        if (matrix[0][0] == INT_MAX) {
            cout << "VNT is Empty" << endl;
            return INT_MAX;
        }
        
        int min = matrix[0][0];
        int r = 0;
        int c = 0;
        
        while (r < height - 1) {
            c = 0;
            /* If the cell on below of our value contains a
             bigger value, swap values */
            if (matrix[r + 1][c] > matrix[r][c])
                swap(matrix[r + 1][c], matrix[r][c]);
            while (c < width - 1) {
                /* If the value is at the most lowest leftmost corner
                 and the cell to its right has a greater value */
                if (r == height - 2 && (matrix[r + 1][c + 1] > matrix[r + 1][c])) {
                    // Swap value with the cell to its right
                    swap(matrix[r + 1][c + 1], matrix[r + 1][c]);
                    // Swap cell above our value with the cell to its right
                    swap(matrix[r][c + 1], matrix[r][c]);
                }
                else if (matrix[r][c + 1] < matrix[r][c]) {
                    // Swap cell above our value with the cell to its right
                    swap(matrix[r][c + 1], matrix[r][c]);
                }
                c++;
            }
            r++;
        }
        matrix[height - 1][width - 1] = INT_MAX;
        return min;
    }
    
    void sort(int arr[], int size){
        VNT temp(sqrt(size) + 1,sqrt(size) + 1);
        int i;
        for (i = 0; i < size; ++i) temp.add(arr[i]);
        for (i = 0; i < size; ++i) arr[i] = temp.getMin();
    }
    bool find(int value){
        int r = height - 1;
        int c = 0;
        while (r >= 0 && value < matrix[r][c]) {
            r--;
        }
            // If value is greater than cell's value, go right
        while(value > matrix[r][c] && c < width - 1) {
            c++;
        }
        if(matrix[r][c] == value) return true;
        return false;
    }
};

