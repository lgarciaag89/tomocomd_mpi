//
// Created by potter on 11/12/18.
//

#ifndef TOMOCOMD_MPI_MATRIX_H
#define TOMOCOMD_MPI_MATRIX_H

#include "Metric.h"

#include <Eigen/Eigen>

#include <openbabel/mol.h>


using namespace OpenBabel;

class Matrix {
protected:
    int size;
    std::map<std::string, int> valencesTable;

public:
    Matrix(int size);

    void show();


//    virtual Matrix* clone() = 0;

//    virtual Matrix* getMatrix(MatrixType type, int p, AlgebraicDescriptorType form, OBMol *mol, Local local, bool isAtomBased, bool isAddH,
//                              bool isDistanceCenter, Cutoff *cutoff) = 0;
//
//    virtual Matrix* toNSMatrix(int p, AlgebraicDescriptorType form, bool isDistanceCenter) = 0;
//
//    virtual Matrix* toSSMatrix(int p, AlgebraicDescriptorType form, bool isDistanceCenter) = 0;
//
//    virtual Matrix* toDSMatrix(int p, AlgebraicDescriptorType form, bool isDistanceCenter) = 0;
//
//    virtual Matrix* toMPMatrix(int p, AlgebraicDescriptorType form, bool isDistanceCenter) = 0;
//
//    void NonWallReturnSelf();
//
//    virtual void WallReturnSelf() = 0;
//
//    virtual void algorithmAccordingToLocal(Local local, OBMol *mol, bool isAtomBased, bool isAddH) = 0;
//
//    virtual void applyCutoff(Cutoff* cutoff) = 0;

};


#endif //TOMOCOMD_MPI_MATRIX_H
