//
// Created by potter on 9/12/18.
//

#include "PerimeterQuaternMetric.h"


double PerimeterQuaternMetric::metricValue(BinaryMetric *metric, OBAtom atom_a, OBAtom atom_b, OBAtom atom_c,OBAtom atom_d) {
    double ab = metric->metricValue(atom_a,atom_b);
    double bc = metric->metricValue(atom_b,atom_c);
    double cd = metric->metricValue(atom_c,atom_d);
    double da = metric->metricValue(atom_d,atom_a);
    return ab+bc+cd+da;
}