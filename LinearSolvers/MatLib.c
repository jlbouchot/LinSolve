#include <stdio.h>
#include <stdlib.h> // Used for calloc
#include <assert.h>

#include "MatLib.h"
#include "math_types.h"

#include "solvers.h"

// Creates an nbRows x nbCols matrix
// Returning a pointer to avoid copying memory around!
Matrix* createZeroMtx(const unsigned int nbRows, const unsigned int nbCols) {

    assert(nbRows > 0U);
    assert(nbCols > 0U);

    // Prepare the output variable
    Matrix* outMtx;
    outMtx = malloc(sizeof(Matrix));
    outMtx->nRows = nbRows;
    outMtx->nCols = nbCols;
    outMtx->matElements = malloc(sizeof(elementType*)*nbRows);

    // Now create the output entries!
    for( unsigned int rowNb = 0U; rowNb < nbRows; ++rowNb ) {
        outMtx->matElements[rowNb] = calloc(sizeof(elementType), nbCols);
    }

    return outMtx;
}

Vector* createZeroVector(const unsigned int nbElemts) {

    assert(nbElemts > 0U);

    Vector* outVector;
    outVector = malloc(sizeof(Vector));
    outVector->nbElements = nbElemts;
    outVector->vecElements = calloc(sizeof(elementType), nbElemts);

    return outVector;
}

Matrix* matmult(Matrix* A, Matrix* B) {
    assert(A->nCols == B->nRows);

    const unsigned int outNbRows = A->nRows;
    const unsigned int outNbCols = B->nCols;
    Matrix* outMtx = createZeroMtx(outNbRows, outNbCols);

    /*
    Some running indices: curCol, curRow, curMid
    */
    unsigned int outRowIdx, outColdIdx, runningIdx;

    // Now fill all the entries
    // Start by running through all rows
    for(outRowIdx = 0U; outRowIdx < outNbRows; outRowIdx++) {
        for(outColdIdx = 0U; outColdIdx < outNbCols; outColdIdx++) {

            // Once the transpose function is done and the dot product implemented, this whole inner inner loop can be replaced by
            // outMtx->matElements[outRowIdx][outColdIdx] = dot_product(A->matElements[outRowIdx], transpose(B)->matElements[outColIdx])
            // Until then, we go through the classical process.

            float currentValue = 0.0f;
            // And now let's feed the monster
            for(runningIdx = 0U; runningIdx < B->nRows; runningIdx++) {
                currentValue += A->matElements[outRowIdx][runningIdx]*B->matElements[runningIdx][outColdIdx];
            }

            outMtx->matElements[outRowIdx][outColdIdx] = currentValue;

        }
    }

    return outMtx;
}
