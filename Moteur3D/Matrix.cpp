//
// Created by Adrien on 04/02/2021.
//

#include "Matrix.h"

Matrix::Matrix(int nb_lines, int nb_cols) {
    lines = nb_lines;
    cols = nb_cols;

    //init matrix with zeros
    for(int i = 0 ; i < nb_lines ; i ++) {
        std::vector<float> line;
        for(int j = 0 ; j < nb_cols ; j ++) {
            line.push_back(0.0f);
        }
        matrix.push_back(line);
        line.clear();
    }
}

Matrix::Matrix(int nb_tot) {
    lines = cols = nb_tot;
    for(int i = 0 ; i < nb_tot ; i ++) {
        std::vector<float> line;
        for(int j = 0 ; j < nb_tot ; j ++) {
            if(i==j) line.push_back(1.0f); // if same col and line, push 1 to create diagonal of identity matrix
            else line.push_back(0.0f); // else 0
        }
        matrix.push_back(line);
        line.clear();
    }
}
// get a column of the matrix
std::vector<float> Matrix::get_col(int idx) {
    check_indexes(0,idx);
    std::vector<float> result;
    for(int i = 0 ; i < matrix.size() ; i ++) {
        result.push_back(matrix.at(i).at(idx));
    }
    return result;
}

// get a line of the matrix
std::vector<float> Matrix::get_line(int idx) {
    check_indexes(idx,0);
    return matrix.at(idx);
}

// get a specific value of the matrix
float Matrix::get_at(int line, int col) {
    check_indexes(line,col);
    return matrix.at(line).at(col);
}

// set a specific value of the matrix
void Matrix::set_at(int line, int col, float value) {
    check_indexes(line,col);
    matrix.at(line).at(col) = value;
}

// check if an operation is not outside of the matrix
void Matrix::check_indexes(int line, int col) {
    if(line >= lines || col >= cols || line < 0 || col < 0) {
        std::cerr << "Given values are outside of the matrix size" << std::endl;
        exit(-1);
    }
}



void Matrix::print() {
    for(int i = 0 ; i < matrix.size() ; i ++) {
        for(int j = 0 ; j < matrix.at(0).size() ; j ++) {
            std::cout << matrix.at(i).at(j) << "\t";
        }
        std::cout << std::endl;
    }
}

VectFloat Matrix::getVect(int idx) {
    check_indexes(3, idx);
    return {matrix.at(0).at(idx), matrix.at(1).at(idx), matrix.at(2).at(idx)};
}

Matrix Matrix::transpose() {
    Matrix transposed(cols,lines);
    for(int i = 0 ; i < matrix.size() ; i ++) {
        for(int j = 0 ; j < matrix.at(0).size() ; j ++) {
            transposed.set_at(j, i, this->get_at(i,j));
        }
    }
    return transposed;
}

// TODO
Matrix Matrix::invert() {
    if(lines != cols) {
        std::cerr << "Cannot invert non squared matrix" << std::endl;
        exit(-1);
    }
    std::cerr << "Not implemented yet" << std::endl;
    exit(-1);
}
/*
 * (
 *
 *
 */


Matrix Matrix::operator*(Matrix e) {
    Matrix new_mat(lines, e.cols);
    if(cols == e.lines) {
     for(int line = 0 ; line < lines ; line++) {
         for(int col = 0 ; col < e.cols ; col++) {
             float value = 0.f;
             for(int curr_col = 0 ; curr_col < cols ; curr_col++) {
                 value += matrix.at(line).at(curr_col) *  e.get_at(curr_col,col);
             }
             new_mat.set_at(line,col, value);
         }
     }
    } else {
        std::cerr << "Cannot multiply matrix with not the same number of lines and cols" << std::endl;
        exit(-1);
    }
   // new_mat.print();
    return new_mat;
}
