//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_WAVEEDGESMETRIC_H
#define TOMOCOMD_MPI_WAVEEDGESMETRIC_H

#include <BinaryMetric.h>
#include <openbabel/atom.h>

using namespace std;
using namespace OpenBabel;

class WaveEdgesMetric : public BinaryMetric{
public:
    WaveEdgesMetric(){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b );
};

#endif //TOMOCOMD_MPI_WAVEEDGESMETRIC_H
