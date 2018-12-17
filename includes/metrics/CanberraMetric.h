//
// Created by potter on 8/12/18.
// Compute Camberra distance between two atoms
//

#ifndef TOMOCOMD_MPI_CANBERRAMETRIC_H
#define TOMOCOMD_MPI_CANBERRAMETRIC_H


#include <BinaryMetric.h>
#include <openbabel/atom.h>

using namespace std;
using namespace OpenBabel;

class CanberraMetric : public BinaryMetric{
public:
    CanberraMetric(){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b );
};


#endif //TOMOCOMD_MPI_CANBERRAMETRIC_H
