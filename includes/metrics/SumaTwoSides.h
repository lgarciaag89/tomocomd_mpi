//
// Created by potter on 9/12/18.
//

#ifndef TOMOCOMD_MPI_SUMATWOSIDES_H
#define TOMOCOMD_MPI_SUMATWOSIDES_H

#include <TernaryMetric.h>

class SumaTwoSides : public TernaryMetric {
public:
    SumaTwoSides(BinaryMetric *metric):TernaryMetric(metric){};
    double metricValue(OBAtom *atom_a, OBAtom *atom_b,OBAtom *atom_c);
};


#endif //TOMOCOMD_MPI_SUMATWOSIDES_H
