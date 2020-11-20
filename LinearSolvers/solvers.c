#include <stdio.h>
#include <stdlib.h> // Used for calloc
#include <assert.h>

#include "solvers.h"


void LUdecomposition(Matrix* inMatrix, Matrix* outL, Matrix* outU){
    printf("I'm here!");
}




CholeskyVector* CholeskyDecomposition(Matrix* inMatrix){ // Add a flag whether to do the multiplication or division
    printf("\nAttempting a Cholesky decomposition\n");
    unsigned int runningIdx = 0U; // This is out of the loops as it is used in various places

    // Allocate memory for output vector
    CholeskyVector* outVector;
    outVector = malloc(sizeof(CholeskyVector));

    // Set output to the default values
    const unsigned int matSize = inMatrix->nCols; // Show be the same as nRows, I leave it up to the user to be careful

    outVector->matDim = matSize;
    outVector->matEntries = createZeroVector(0.5*matSize*(matSize+1));

    // Finally start the Cholesky decomposition
    // We look over all rows
    unsigned int lowerIdxStart = 0U;
    for(unsigned int rowNb = 0U; rowNb < matSize; ++rowNb) {
        lowerIdxStart += rowNb;

        // Now iterate over all the elements (up to the one prior to the diagonal)
        unsigned int higherIdxStart = 0U;
        for(unsigned int colNb = 0U; colNb < rowNb; ++colNb) {
            elementType localSum = 0;

            higherIdxStart += colNb; // This is used to keep track of one of the indices where are used in the inner loop, namely the one which is "higher" in the lower matrix
            for(runningIdx = 0U; runningIdx < colNb; ++runningIdx) {
                localSum += outVector->matEntries->vecElements[higherIdxStart+runningIdx]*outVector->matEntries->vecElements[lowerIdxStart+runningIdx];
                // localSum += entryFromCholVectorAt(outVector->matEntries, colNb, k)*entryFromCholVectorAt(outVector->matEntries, rowNb, k); // This is not the most efficient thing to do.
            }
            // We have summed up everything we needed.
            outVector->matEntries->vecElements[lowerIdxStart+colNb] = (inMatrix->matElements[rowNb][colNb]-localSum)/outVector->matEntries->vecElements[higherIdxStart+colNb];
        }
        outVector->matEntries->vecElements[lowerIdxStart+rowNb] = inMatrix->matElements[rowNb][rowNb];
        for(runningIdx = 0U; runningIdx+1 < rowNb; ++runningIdx) { // Not happy with the +1, but needed to avoid overflowing the unsigned int
            outVector->matEntries->vecElements[lowerIdxStart+rowNb] -= outVector->matEntries->vecElements[lowerIdxStart+runningIdx]*outVector->matEntries->vecElements[lowerIdxStart+runningIdx];
        }
        outVector->matEntries->vecElements[lowerIdxStart+rowNb] = sqrt(outVector->matEntries->vecElements[lowerIdxStart+rowNb]);

    }

    printf("Cholesky done\n");

    return outVector;

}
