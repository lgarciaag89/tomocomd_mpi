//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_ANGULARSEPARATIONMETRIC_H
#define TOMOCOMD_MPI_ANGULARSEPARATIONMETRIC_H


#include <string>
#include <openbabel/atom.h>
#include "BinaryMetric.h"

using namespace std;
using namespace OpenBabel;
class AngularSeparationMetric : public BinaryMetric{

public:
    AngularSeparationMetric(){};
    double metricValue(OBAtom atom_a, OBAtom atom_b );
};

#endif //TOMOCOMD_MPI_ANGULARSEPARATIONMETRIC_H
