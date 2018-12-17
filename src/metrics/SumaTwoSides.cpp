//
// Created by potter on 9/12/18.
//

#include "SumaTwoSides.h"

double SumaTwoSides::metricValue( OBAtom *atom_a, OBAtom *atom_b,
                                 OBAtom *atom_c) {
    double ab = metric->metricValue(atom_a,atom_b);
    double bc = metric->metricValue(atom_b,atom_c);
    return ab+bc;
}