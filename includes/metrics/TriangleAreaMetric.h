//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_TRIANGLEAREAMETRIC_H
#define TOMOCOMD_MPI_TRIANGLEAREAMETRIC_H

#include <TernaryMetric.h>

class TriangleAreaMetric : public TernaryMetric {
public:
    TriangleAreaMetric(BinaryMetric *metric):TernaryMetric(metric){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b,OBAtom *atom_c);
};


#endif //TOMOCOMD_MPI_TRIANGLEAREAMETRIC_H
