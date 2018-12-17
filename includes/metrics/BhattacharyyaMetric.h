//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_BHATTACHARYYAMETRIC_H
#define TOMOCOMD_MPI_BHATTACHARYYAMETRIC_H


#include "BinaryMetric.h"
#include <openbabel/atom.h>

using namespace OpenBabel;

class BhattacharyyaMetric : public BinaryMetric {
protected:
    double p;
public:
    double metricValue(OBAtom *atom_a, OBAtom *atom_b );
};


#endif //TOMOCOMD_MPI_BHATTACHARYYAMETRIC_H
