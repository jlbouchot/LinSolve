#ifndef SOLVERS_H_INCLUDED
#define SOLVERS_H_INCLUDED

#include "math_types.h"
#include <math.h> // Used for the square root

/* Cholesky decomposition.
 * Computes the LU decomposition of a matrix.
 * @param[in] inMatrix An n x n matrix which we try to decompose.
 * @return (n+1)n/2 Vector containing the entries of the L matrix, row wise
 * @warning: The input matrix should be symmetric definite. No checks is made for this.
 */
CholeskyVector* CholeskyDecomposition(Matrix* inMatrix);

/* Cholesky decomposition.
 * Computes the LU decomposition of a matrix.
 * @param[in,out] inMatrix An n x n matrix which we try to decompose. It is slowly replaced by the L matrix on the lower triangle (the upper part is left unchanged)
 * @warning: The input matrix should be symmetric definite. No checks is made for this.
 */
// void CholeskyDecomposition(Matrix* inOutMatrix); // Overloading not permitted in C -> Need to change names.

/* LUdecomposition.
 * Computes the LU decomposition of a matrix.
 * @param[in] inMatrix float* An n x n matrix which we try to decompose.
 * @param[in] n the dimension of the matrix // This is useless using the matrix structure.
 * @param[out] outL a matrix containing the Lower triangular matrix
 * @param[out] outU a matrix containing the Upper triangular matrix
 */
void LUdecomposition(Matrix* inMatrix, Matrix *outL, Matrix *outU);

#endif // SOLVERS_H_INCLUDED
