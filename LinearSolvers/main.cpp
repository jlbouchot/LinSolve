#include <iostream>
#include <assert.h>

#include <cmath>

extern "C" {
    #include "solvers.h"
    #include "math_types.h"
    #include "MatLib.h"
}

using namespace std;


int main()
{
    cout << "Hello world!" << endl;
    const unsigned int nbRows = 2;
    const unsigned int nbCols = nbRows;

    Matrix* aMatrix = createZeroMtx(nbRows, nbCols);
    Matrix* anotherMatrix = createZeroMtx(nbRows, nbCols);
    Matrix* oneLastMatrix = createZeroMtx(nbRows, nbCols);
    LUdecomposition(aMatrix, anotherMatrix, oneLastMatrix);

    aMatrix->matElements[0][0] = 2.0f;
    aMatrix->matElements[0][1] = 1.0f;
    aMatrix->matElements[1][0] = 1.0f;
    aMatrix->matElements[1][1] = 2.0f;

    CholeskyVector* cholVec;
    cholVec = CholeskyDecomposition(aMatrix);
    printf("%f, %f, %f\n\n", cholVec->matEntries->vecElements[0], cholVec->matEntries->vecElements[1], cholVec->matEntries->vecElements[2]);

    // Let's try the matrix multiplication thing
    Matrix* squareOfA = matmult(aMatrix, aMatrix);
    printf("\n\t Compute the square of the previous matrix \n %f, %f, %f, %f\n\n", squareOfA->matElements[0][0], squareOfA->matElements[0][1], squareOfA->matElements[1][0], squareOfA->matElements[1][1]); // This should be [5, 4, 4, 5]

    // Testing the matmult function
    const uint8_t sizeMat = 2;
    Matrix* A = createZeroMtx(sizeMat, sizeMat);
    A->matElements[0][0] = std::sqrt(2.0)/2.0;
    A->matElements[0][1] = A->matElements[0][0];
    A->matElements[1][1] = A->matElements[0][0];
    A->matElements[1][0] = A->matElements[0][0];

    Matrix* shouldBeIdentity = matmult(A, A);
    assert(shouldBeIdentity->matElements[0][0] == 1.0);
    assert(shouldBeIdentity->matElements[0][1] == 0.0);

    // Test lower times upper.
    upperTriangular* upperones = malloc(sizeof(upperTriangular));
    upperones->matDim = 3;

    return 0;
}
