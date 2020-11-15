#ifndef MATLIB_H_INCLUDED
#define MATLIB_H_INCLUDED

#include <cmath>
#include "math_types.h"

// Some basic matrix operations
Matrix* matmult(Matrix* A, Matrix* B);
void matmult_replace(Matrix* A, Matrix* B); // Same as above, but overwrites the matrix A
Matrix* cholvec2matrix(CholeskyVector* cholVec);
Vector* matvecmult(Matrix* A, Vector* v);
Matrix* transpose(Matrix* M);
void transpose_replace(Matrix* M) // Same as transpose, but replaces the input matrix.

// Some basic linear algebra stuff
 GramSchmidt_replace(Matrix* M);
void GramSchmidt_replace(Matrix* M);
void QR_full(Matrix* M, Matrix* Q, upperTriangular* R);



#endif // MATLIB_H_INCLUDED
