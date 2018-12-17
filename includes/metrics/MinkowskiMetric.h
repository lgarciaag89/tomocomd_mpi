//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_MINKOWSKIMETRIC_H
#define TOMOCOMD_MPI_MINKOWSKIMETRIC_H


#include "BinaryMetric.h"
#include <openbabel/atom.h>

using namespace OpenBabel;

class MinkowskiMetric : public BinaryMetric {
protected:
    double p;
public:
    MinkowskiMetric():BinaryMetric(){p=0.0;};
    MinkowskiMetric(double p){this->p=p;};
    ~MinkowskiMetric(){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b );
};


#endif //TOMOCOMD_MPI_MINKOWSKIMETRIC_H
