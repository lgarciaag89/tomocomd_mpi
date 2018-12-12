//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_PYRAMIDVOLUMEMETRIC_H
#define TOMOCOMD_MPI_PYRAMIDVOLUMEMETRIC_H


#include <QuaternMetric.h>

class PyramidVolumeMetric : public QuaternMetric{
public:
    PyramidVolumeMetric(){};
    ~PyramidVolumeMetric(){};
    double metricValue(BinaryMetric *metric,OBAtom atom_a, OBAtom atom_b,OBAtom atom_c,OBAtom atom_d);
};


#endif //TOMOCOMD_MPI_PYRAMIDVOLUMEMETRIC_H
