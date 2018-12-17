//
// Created by potter on 11/12/18.
//

#ifndef TOMOCOMD_MPI_COMPUTEDIAGONAL_H
#define TOMOCOMD_MPI_COMPUTEDIAGONAL_H

#include "Metric.h"

#include <string>

class ComputeDiagonal {
    double* LonePairDistanceCenter(std::string molFile, bool isHardSoftSelected, bool isAddH, bool isLonePair, bool isDistanceCenter, Metric *metric);
};


#endif //TOMOCOMD_MPI_COMPUTEDIAGONAL_H
