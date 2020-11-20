#ifndef MATH_TYPES_H_INCLUDED
#define MATH_TYPES_H_INCLUDED

// Macro to define the type of data inside the matrix.
// This will eventually be project dependent / architecture dependent.
typedef float elementType;

typedef struct Vector {
    unsigned int nbElements;
    elementType* vecElements;
} Vector;

// A Cholesky vector is a vector containing the entries of the L matrix, row wise
typedef struct CholeskyVector {
    unsigned int matDim;
    Vector* matEntries;
} CholeskyVector;

// These are place holders for vectors representing upper triangular or lower triangular matrices
// They don't add any thing when compared to a CholeskyVector.
// A warning though!
// An upper triangular matrix has its values indexed column wise, not row wise, i.e.
// element[0] = M(0,0)
// element[1] = M(0,1) -> No surprise so far
// element[2] = M(1,1) -> One could have expected M(0,2) here.
typedef CholeskyVector upperTriangular;
typedef CholeskyVector lowerTriangular;

typedef struct Matrix {
    unsigned int nRows;
    unsigned int nCols;
    elementType** matElements;
} Matrix;

#endif // MATH_TYPES_H_INCLUDED
