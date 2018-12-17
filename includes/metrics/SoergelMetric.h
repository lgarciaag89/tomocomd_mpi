//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_SOERGELMETRIC_H
#define TOMOCOMD_MPI_SOERGELMETRIC_H


#include <BinaryMetric.h>
#include <openbabel/atom.h>

using namespace std;
using namespace OpenBabel;

class SoergelMetric : public BinaryMetric{
public:
    SoergelMetric(){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b );
};


#endif //TOMOCOMD_MPI_SOERGELMETRIC_H
