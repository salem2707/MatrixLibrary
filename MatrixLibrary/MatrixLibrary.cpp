#include "pch.h"
#include "MatrixLibrary.h"
#include <cstdlib>

int** MultiplicateMatrixByNumber(int** matrix, int columns, int rows, int number) {
    
    if (!matrix || columns <= 0 || rows <= 0) {
        return nullptr;
    }

    int** result = static_cast<int**>(std::malloc(rows * sizeof(int*)));
    if (!result) {
        return nullptr;
    }

    for (int i = 0; i < rows; ++i) {
        result[i] = static_cast<int*>(std::malloc(columns * sizeof(int)));
        if (!result[i]) {
            for (int j = 0; j < i; ++j) {
                std::free(result[j]);
            }
            std::free(result);
            return nullptr;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix[i][j] * number;
        }
    }

    return result;
}
