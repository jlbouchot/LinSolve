#ifndef MATLIB_H_INCLUDED
#define MATLIB_H_INCLUDED

#include "math_types.h"

// Basic inits
Matrix* createZeroMtx(const unsigned int nbRows, const unsigned int nbCols);
Vector* createZeroVector(const unsigned int nbElemts);

// Some basic matrix operations
Matrix* matmult(Matrix* A, Matrix* B);
void matmult_replace(Matrix* A, Matrix* B); // Same as above, but overwrites the matrix A
Matrix* cholvec2matrix(CholeskyVector* cholVec);
Vector* matvecmult(Matrix* A, Vector* v);
Matrix* transpose(Matrix* M);
void transpose_replace(Matrix* M); // Same as transpose, but replaces the input matrix.
Matrix* lowerTimesUpper(lowerTriangular* L, upperTriangular* U);

// Obtain the index of an entry of a Lower triangular matrix at position x,y from a single vector
/* entryAt. Converts the (row, col) index pair of a matrix into a single index which can be used for triangular matrices represented as one dimensional vectors
 * @param[in] matDim     the dimension of the (expected square) matrix we consider
 * @param[in] rowIdx     the row index of the entry we want to retrieve
 * @param[in] colIdx     the column index of the entry we want to retrieve
 * @param[in] doUpper    is 0 if we assume the underlying to be lower triangular. Any other value means an upper triangular matrix
 * @return               The index of the position of the entry in the underlying vector
 */
int entryAt(const unsigned int matDim, const int rowIdx, const int colIdx, const unsigned char doUpper);

// Some basic linear algebra stuff
void GramSchmidt_replace(Matrix* M);
void QR_full(Matrix* M, Matrix* Q, upperTriangular* R);
upperTriangular* = transpose(lowerTriangular); // This is, if you think about it, pretty useless. It's just a copy of the memory content.


#endif // MATLIB_H_INCLUDED
