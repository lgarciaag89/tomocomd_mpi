//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_DIHEDRALANGLEMETRIC_H
#define TOMOCOMD_MPI_DIHEDRALANGLEMETRIC_H

#include <QuaternMetric.h>

class DihedralAngleMetric : public QuaternMetric{
public:
    DihedralAngleMetric(BinaryMetric *metric):QuaternMetric(metric){};
    double metricValue(BinaryMetric *metric,OBAtom *atom_a, OBAtom *atom_b,OBAtom *atom_c,OBAtom *atom_d);
};


#endif //TOMOCOMD_MPI_DIHEDRALANGLEMETRIC_H
