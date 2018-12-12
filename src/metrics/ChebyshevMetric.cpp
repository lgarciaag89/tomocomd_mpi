//
// Created by potter on 9/12/18.
//

#include "ChebyshevMetric.h"

double ChebyshevMetric::metricValue(OBAtom atom_a, OBAtom atom_b) {
    OpenBabel::vector3 coords_a = atom_a.GetVector();
    OpenBabel::vector3 coords_b = atom_b.GetVector();

    double result = 0.0;
    for(int i= 0; i < 3 ; i++){
        double a = coords_a[i],b = coords_b[i];
        double partial_result = fabs(a-b);
        result=(result > partial_result ? result : partial_result);
    }
    return result;
}