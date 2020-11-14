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

typedef struct Matrix {
    unsigned int nRows;
    unsigned int nCols;
    elementType** matElements;
} Matrix;

#endif // MATH_TYPES_H_INCLUDED
