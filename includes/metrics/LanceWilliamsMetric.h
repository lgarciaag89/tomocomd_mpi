//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_LANCEWILLIAMSMETRIC_H
#define TOMOCOMD_MPI_LANCEWILLIAMSMETRIC_H

#include <BinaryMetric.h>
#include <string>
#include <openbabel/atom.h>

using namespace std;
using namespace OpenBabel;
class LanceWilliamsMetric : public BinaryMetric{

public:
    LanceWilliamsMetric(){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b );
};


#endif //TOMOCOMD_MPI_LANCEWILLIAMSMETRIC_H
