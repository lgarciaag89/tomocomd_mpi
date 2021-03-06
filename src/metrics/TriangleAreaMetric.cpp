//
// Created by potter on 9/12/18.
//

#include "TriangleAreaMetric.h"

double TriangleAreaMetric::metricValue( OBAtom *atom_a, OBAtom *atom_b,
                                       OBAtom *atom_c) {
    double ab = metric->metricValue(atom_a,atom_b);
    double bc = metric->metricValue(atom_b,atom_c);
    double ca = metric->metricValue(atom_c,atom_a);
    double s = (ab+bc+ca)/2;
    double result = sqrt(s*(s-ab)*(s-bc)*(s-ca));
    return result;
}