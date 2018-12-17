//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_SUMTHREESIDES_H
#define TOMOCOMD_MPI_SUMTHREESIDES_H


#include <QuaternMetric.h>

class SumThreeSides : public QuaternMetric{
    SumThreeSides(BinaryMetric *metric):QuaternMetric(metric){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b,OBAtom *atom_c,OBAtom *atom_d);
};


#endif //TOMOCOMD_MPI_SUMTHREESIDES_H
