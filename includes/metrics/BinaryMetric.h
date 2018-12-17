//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_BINARYMETRIC_H
#define TOMOCOMD_MPI_BINARYMETRIC_H

#include <iostream>
#include <string>
#include <Metric.h>

#include <openbabel/atom.h>

using namespace OpenBabel;
class BinaryMetric : public Metric {
protected:
    std::string key;

public:
    BinaryMetric(){};
    ~BinaryMetric(){};
    virtual double metricValue(OBAtom *atom_a, OBAtom *atom_b)=0;
//    virtual Metric* clone() = 0;
};

#endif //TOMOCOMD_MPI_BINARYMETRIC_H
