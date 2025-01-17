//
// Created by Adrien on 04/02/2021.
//

#ifndef MOTEUR3D_MATRIX_H
#define MOTEUR3D_MATRIX_H

#include "VectFloat.h"
#include "Vect4Float.h"
#include <vector>
#include <iostream>
class VectFloat;
class Vect4Float;

class Matrix {

private:
    void check_indexes(int line, int col); // checks if indexes are not outside of the matrix

public:
    std::vector< std::vector<float> > matrix; //double chained vector to represent our matrix
    int lines; // number of lines
    int cols; // number of columns
    Matrix(int nb_lines, int nb_cols); // default constructor
    Matrix(int nb_tot); // identity matrix

    // Basic stuff
    std::vector<float> get_col(int idx); // get the idx column of the matrix
    std::vector<float> get_line(int idx); // get the idx line of the matrix
    float get_at(int line, int col); // get the value at the given indexes in the matrix
    void set_at(int line, int col, float value); // sets the value at the given indexes in the matrix
    void print(); // prints the matrix

    VectFloat getVect(int idx); // gets the vector on the idx column of the matrix (usually the first)
    Vect4Float getVect4(int idx);

    static Matrix submatrix(Matrix m, int line, int col);
    static Matrix cofactor(Matrix m);

    // Matrix operations
    static float determinant(Matrix m); // calculate the determinant of the matrix to know if we can invert it
    Matrix transpose(); // transpose the matrix
    static Matrix invert(Matrix m); // invert the matrix
    Matrix operator* (Matrix e); // multiply two matrixes

};


#endif //MOTEUR3D_MATRIX_H
