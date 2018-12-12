//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_MANHATTANMETRIC_H
#define TOMOCOMD_MPI_MANHATTANMETRIC_H

#include <MinkowskiMetric.h>
#include <openbabel/atom.h>

using namespace OpenBabel;

class ManhattanMetric : public MinkowskiMetric{
protected:
    double p;
public:
    ManhattanMetric():MinkowskiMetric(1){};
};


#endif //TOMOCOMD_MPI_MANHATTANMETRIC_H
