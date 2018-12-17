//
// Created by potter on 12/12/18.
//

#ifndef TOMOCOMD_MPI_SYMMATRIX_H
#define TOMOCOMD_MPI_SYMMATRIX_H

#include "Matrix.h"
#include "BinaryMetric.h"
#include <string>
#include <openbabel/mol.h>

using namespace OpenBabel;

class SymMatrix : public Matrix {
protected:
    Eigen::SparseMatrix<double> matrix;
public:
    SymMatrix(int rsize):Matrix(rsize){
        this->matrix.resize(size,size);
    };

    void createNSMatrix(OBMol *mol, BinaryMetric* metric, bool isAddH, bool isLonePair, bool isDistanceCenter, std::string molFilename, bool isHardSoftSelected);
    void set(int row, int col, double value);
    double get(int row, int col);

    void show();
};



#endif //TOMOCOMD_MPI_SYMMATRIX_H
