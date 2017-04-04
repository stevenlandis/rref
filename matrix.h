#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include"fraction.h"
using namespace std;

class Matrix {
private:
    Fraction *c;
    //pointer to contents array

    int rows, cols, len;
    void decrement(int row, int col, Fraction value) {
    //decreases a cell by a certain amount
    //used in rref
        if (row >= 0 and row < rows and col >= 0 and col < cols) {
            c[col + row * cols].decrement(value);
        }
    }
    void scale(int row, int col, Fraction value) {
    //scales a cell by a certain amount
    //used in rref
        if (row >= 0 and row < rows and col >= 0 and col < cols) {
            c[col + row * cols].scale(value);
        }
    }

public:
    Matrix(int rows, int cols) {
    //initializes empty matrix
        this->rows = rows;
        this->cols = cols;
        this->len = rows*cols;
        c = new Fraction[rows*cols];
        zero();
    }
    Matrix(int rows, int cols, Fraction * constructorArray) {
    //initializes matrix from a one-dimensional array
        this->rows = rows;
        this->cols = cols;
        this->len = rows*cols;
        c = constructorArray;
    }
    void zero() {
        //sets all cells to zero
        for (int i = 0; i < len; i++) {
            c[i].zero();
        }
    }
    Fraction get(int row, int col) {
    //retrieves the value in a cell
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return Fraction(0,1);
        }
        return c[col + row * cols];
    }
    void set(int row, int col, Fraction value) {
    //sets the value of a cell
        if (row >= 0 and row < rows and col >= 0 and col < cols) {
            c[col + row * cols] = value;
        }
    }
    void rref() {
    //puts the matrix in rref
        for (int i = 0; i < cols; i++) {
            int pivot = -1;
            //pivot set to sentinal value

            //Search for pivot cell in current column:
            for (int j = 0; j < rows; j++) {
                bool zeroes = true;
                for (int k = i-1; k >= 0; k--) {
                    if (!(get(j,k).isZero())) {
                        zeroes = false;
                        k = 0;
                        //stop the loop early
                    }
                }
                if (zeroes) {
                    pivot = j;
                    j = rows;
                    //found pivot, stop loop early
                }
            }
            if (pivot >= 0) {
            //if pivot cell was found:
                if (get(pivot, i).isZero()) {
                //if the pivot cell is zero, switch with another row:
                    for (int j = pivot + 1; j < rows; j++) {
                        if (!(get(j,i).isZero())) {
                            //swap the two rows
                            for (int k = 0; k < cols; k++) {
                                //swap (pivot, k) and (j, k)
                                Fraction buffer = get(pivot, k);
                                set(pivot, k, get(j, k));
                                set(j, k, buffer);
                            }
                            j = rows;
                        }
                    }
                }
                if (!(get(pivot, i).isZero())) {
                //if the switching worked:
                    Fraction scalar = get(pivot, i).inverse();
                    for (int j = 0; j < cols; j++) {
                        scale(pivot, j, scalar);
                    }
                    for (int j = 0; j < rows; j++) {
                        if (j != pivot) {
                            Fraction scalar = get(j, i);
                            for (int k = 0; k < cols; k++) {
                                decrement(j, k, get(pivot, k).scale(scalar));
                            }
                        }
                    }
                }
            }
        }
    }
    void disp() {
    //displays the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                get(i,j).disp();
                cout << " ";
            }
            cout << endl;
        }
    }
};

#endif
