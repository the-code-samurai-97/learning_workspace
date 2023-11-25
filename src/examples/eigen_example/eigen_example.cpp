#include <iostream>
#include <Eigen/Dense>

int main() {
    // Define matrices
    Eigen::MatrixXd matrix1(2, 3);
    matrix1 << 1, 2, 3,
               4, 5, 6;
    std::cout << " matrix 1:\n" << matrix1 << std::endl;

    Eigen::MatrixXd matrix2(3, 2);
    matrix2 << 7, 8,
               9, 10,
               11, 12;
    std::cout << " matrix 2:\n" << matrix2 << std::endl;

    // Perform matrix multiplication
    const Eigen::MatrixXd result = matrix1 * matrix2;

    // Print the result
    std::cout << "Result of matrix multiplication:\n" << result << std::endl;

    // Print Eigen version
    std::cout << "Eigen version: " << EIGEN_WORLD_VERSION << "."
              << EIGEN_MAJOR_VERSION << "."
              << EIGEN_MINOR_VERSION << std::endl;

    return 0;
}
