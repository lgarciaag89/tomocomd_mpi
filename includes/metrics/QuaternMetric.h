//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_QUATERNMETRIC_H
#define TOMOCOMD_MPI_QUATERNMETRIC_H

#include <iostream>
#include <string>
#include <BinaryMetric.h>

#include <openbabel/atom.h>

using namespace OpenBabel;
class QuaternMetric : public Metric {
protected:
    BinaryMetric *metric;
public:
    QuaternMetric(BinaryMetric *metric){this->metric=metric;};
    ~QuaternMetric(){delete metric;};
    void setMetric(BinaryMetric *metric){this->metric=metric;};
    virtual double metricValue(OBAtom *atom_a, OBAtom *atom_b,OBAtom *atom_c, OBAtom *atom_d)=0;
//    virtual Metric* clone() = 0;
};

#endif //TOMOCOMD_MPI_QUATERNMETRIC_H
