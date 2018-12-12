//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_BONDANGLEMETRIC_H
#define TOMOCOMD_MPI_BONDANGLEMETRIC_H


#include "TernaryMetric.h"

class BondAngleMetric : public TernaryMetric {
public:
    BondAngleMetric(){};
    double metricValue(BinaryMetric *metric,OBAtom atom_a, OBAtom atom_b,OBAtom atom_c);
};


#endif //TOMOCOMD_MPI_BONDANGLEMETRIC_H
