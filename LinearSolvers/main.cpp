#include <iostream>

extern "C" {
    #include "solvers.h"
    #include "math_types.h"
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
    printf("%f, %f, %f", cholVec->matEntries->vecElements[0], cholVec->matEntries->vecElements[1], cholVec->matEntries->vecElements[2]);
    return 0;
}
