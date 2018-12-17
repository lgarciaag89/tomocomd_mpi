//
// Created by potter on 13/12/18.
//

#ifndef TOMOCOMD_MPI_GENMATRIXQUATERNS_H
#define TOMOCOMD_MPI_GENMATRIXQUATERNS_H

#include "Matrix.h"
#include <string>
#include <unsupported/Eigen/CXX11/Tensor>
#include <QuaternMetric.h>

class GenMatrixQuaterns  : public Matrix{
private:
    Eigen::Tensor<double,4> matrix;
    int size;

    std::map<std::string, int> valencesTable;
public:
    GenMatrixQuaterns(int size):Matrix(size){
        matrix.resize(size,size,size,size);
    };

    void createNSMatrix(OBMol *mol, QuaternMetric* metric, bool isAddH, bool isLonePair,
                        bool isDistanceCenter, std::string molFilename, bool isHardSoftSelected);
};


#endif //TOMOCOMD_MPI_GENMATRIXQUATERNS_H
