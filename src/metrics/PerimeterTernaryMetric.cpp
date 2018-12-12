//
// Created by potter on 9/12/18.
//

#include "PerimeterTernaryMetric.h"

double PerimeterTernaryMetric::metricValue(BinaryMetric *metric, OBAtom atom_a, OBAtom atom_b, OBAtom atom_c) {
    double ab = metric->metricValue(atom_a,atom_b);
    double bc = metric->metricValue(atom_b,atom_c);
    double ca = metric->metricValue(atom_c,atom_a);
    return ab+bc+ca;
}