//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_PERIMETERQUATERNMETRIC_H
#define TOMOCOMD_MPI_PERIMETERQUATERNMETRIC_H


#include <QuaternMetric.h>

class PerimeterQuaternMetric : public QuaternMetric{
public:
    PerimeterQuaternMetric(){};
    double metricValue(BinaryMetric *metric,OBAtom atom_a, OBAtom atom_b,OBAtom atom_c,OBAtom atom_d);

};


#endif //TOMOCOMD_MPI_PERIMETERQUATERNMETRIC_H
