//
// Created by potter on 9/12/18.
//

#include "BhattacharyyaMetric.h"

double BhattacharyyaMetric::metricValue(OBAtom *atom_a, OBAtom *atom_b) {
    OpenBabel::vector3 coords_a = atom_a->GetVector();
    OpenBabel::vector3 coords_b = atom_b->GetVector();

    double result = 0.0;
    for(int i= 0; i < 3 ; i++){
        double a = sqrt(coords_a[i]),b = sqrt(coords_b[i]);
        result+=pow(a-b,2);
    }
    return sqrt(result);
}