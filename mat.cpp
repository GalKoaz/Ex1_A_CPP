//
// Created by Gal on 04/03/2022.
//

#include <iostream>
#include "mat.hpp"

string ariel::mat(int column, int row, char a, char b) {
    if (column < 0 || row < 0) {
        throw std::invalid_argument("Mat size is always positive");
    }
    if (column % 2 == 0 || row % 2 == 0) {
        throw std::invalid_argument("Mat size is always odd");
    }
    if (a == ' ' || b == ' ' || a == '\n' || b == '\n' || a == '\r' || b == '\r' || a == '\t' || b == '\t') {
        throw std::invalid_argument("Mat is always with no spaces");
    }
    if (a == b) {
        throw std::invalid_argument("Mat is always has two different chars");
    }
    int s_row = 0;
    int s_col = 0;
    int save_row = row;
    int save_col = column;
    char mat[row][column];
    char temp = a;
    while (s_row < row && s_col < column) {
        for (int i = s_col; i < column; ++i) {
            mat[s_row][i] = temp;
        }
        s_row++;
        for (int i = s_row; i < row; ++i) {
            mat[i][column - 1] = temp;
        }
        column--;
        if (s_row < row) {
            for (int i = column - 1; i >= s_col; --i) {
                mat[row - 1][i] = temp;
            }
            row--;
        }
        if (s_col < column) {
            for (int i = row - 1; i >= s_row; --i) {
                mat[i][s_col] = temp;
            }
            s_col++;
        }
        if (temp == a) { temp = b; } else { temp = a; }
    }
    string matrix;
    for (int i = 0; i < save_row; i++) {
        for (int j = 0; j < save_col; j++) {
            matrix.push_back(mat[i][j]);
        }
        if (i + 1 < save_row) {
            matrix.push_back('\n');
        }
    }
    return matrix;
}