//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_EUCLIDIANMETRIC_H
#define TOMOCOMD_MPI_EUCLIDIANMETRIC_H


#include <MinkowskiMetric.h>
#include <openbabel/atom.h>

using namespace OpenBabel;

class EuclidianMetric : public MinkowskiMetric{
protected:
    double p;
public:
    EuclidianMetric():MinkowskiMetric(2){};
};


#endif //TOMOCOMD_MPI_EUCLIDIANMETRIC_H
