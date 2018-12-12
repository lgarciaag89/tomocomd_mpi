//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_PERIMETERMETRIC_H
#define TOMOCOMD_MPI_PERIMETERMETRIC_H

#include <TernaryMetric.h>

class PerimeterTernaryMetric : public TernaryMetric {
public:
    PerimeterTernaryMetric(){};
    double metricValue(BinaryMetric *metric,OBAtom atom_a, OBAtom atom_b,OBAtom atom_c);
};


#endif //TOMOCOMD_MPI_PERIMETERMETRIC_H
