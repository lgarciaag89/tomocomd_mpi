//
// Created by potter on 8/12/18.
//

#include "CanberraMetric.h"


double CanberraMetric::metricValue(OBAtom *atom_a, OBAtom *atom_b){
    OpenBabel::vector3 coords_a = atom_a->GetVector();
    OpenBabel::vector3 coords_b = atom_b->GetVector();

    double result = 0.0;
    for(int i= 0; i < 3 ; i++){
        double a = coords_a[i],b = coords_b[i];
        double partial_result = fabs(a-b)/(fabs(a) + fabs(b));
        result+=(std::isnan(partial_result) ? 0 : partial_result);
    }
    return result;
}

