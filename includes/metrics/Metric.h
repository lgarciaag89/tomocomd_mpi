//
// Created by potter on 8/12/18.
//

#ifndef TOMOCOMD_MPI_METRIC_H
#define TOMOCOMD_MPI_METRIC_H

#include <iostream>
#include <string>

#include <openbabel/atom.h>

using namespace OpenBabel;
class Metric {
protected:
    std::string key;

public:
    Metric(){};
    ~Metric(){};
};


#endif //TOMOCOMD_MPI_METRIC_H
