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

// Some basic linear algebra stuff
void GramSchmidt_replace(Matrix* M);
void GramSchmidt_replace(Matrix* M);
void QR_full(Matrix* M, Matrix* Q, upperTriangular* R);
upperTriangular* = transpose(lowerTriangular); // This is, if you think about it, pretty useless. It's just a copy of the memory content.
Matrix* lowerTimesUpper(lowerTriangular* L, upperTriangular* U);


#endif // MATLIB_H_INCLUDED
