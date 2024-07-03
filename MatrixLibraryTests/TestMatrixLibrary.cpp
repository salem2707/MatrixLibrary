#include "pch.h"
#include "MatrixLibrary.h"

TEST(MultiplicateMatrixByNumberTests, NullMatrix) {
    int** result = MultiplicateMatrixByNumber(nullptr, 3, 3, 5);
    EXPECT_EQ(result, nullptr);
}

TEST(MultiplicateMatrixByNumberTests, InvalidDimensions) {
    int** matrix = nullptr;
    int** result = MultiplicateMatrixByNumber(matrix, -1, 3, 5);
    EXPECT_EQ(result, nullptr);

    result = MultiplicateMatrixByNumber(matrix, 3, 0, 5);
    EXPECT_EQ(result, nullptr);
}

TEST(MultiplicateMatrixByNumberTests, ValidMatrix) {
    int rows = 2;
    int columns = 2;
    int** matrix = static_cast<int**>(std::malloc(rows * sizeof(int*)));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = static_cast<int*>(std::malloc(columns * sizeof(int)));
    }
    matrix[0][0] = 1; matrix[0][1] = 2;
    matrix[1][0] = 3; matrix[1][1] = 4;

    int number = 3;
    int** result = MultiplicateMatrixByNumber(matrix, columns, rows, number);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0][0], 3);
    EXPECT_EQ(result[0][1], 6);
    EXPECT_EQ(result[1][0], 9);
    EXPECT_EQ(result[1][1], 12);

    for (int i = 0; i < rows; ++i) {
        std::free(matrix[i]);
        std::free(result[i]);
    }
    std::free(matrix);
    std::free(result);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
