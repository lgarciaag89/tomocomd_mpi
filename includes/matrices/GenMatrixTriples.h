//
// Created by potter on 12/12/18.
//

#ifndef TOMOCOMD_MPI_GENMATRIXTRIPLES_H
#define TOMOCOMD_MPI_GENMATRIXTRIPLES_H

#include <string>
#include "Matrix.h"
#include "TernaryMetric.h"

#include <unsupported/Eigen/CXX11/Tensor>

class GenMatrixTriples : public Matrix{
private:
    Eigen::Tensor<double,3> matrix;
    int size;

    std::map<std::string, int> valencesTable;
public:
    GenMatrixTriples(int size):Matrix(size){
        matrix.resize(size,size,size);
    };

    void createNSMatrix(OBMol *mol, TernaryMetric* metric, bool isAddH, bool isLonePair,
                        bool isDistanceCenter, std::string molFilename, bool isHardSoftSelected);
};


#endif //TOMOCOMD_MPI_GENMATRIXTRIPLES_H
