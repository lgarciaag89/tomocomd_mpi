//
// Created by potter on 9/12/18.
//

#include "LanceWilliamsMetric.h"

double LanceWilliamsMetric::metricValue(OBAtom atom_a, OBAtom atom_b){
    OpenBabel::vector3 coords_a = atom_a.GetVector();
    OpenBabel::vector3 coords_b = atom_b.GetVector();

    double result = 0.0, dividendo = 0, divisor = 0;
    for(int i= 0; i < 3 ; i++){
        double a = coords_a[i],b = coords_b[i];
        dividendo+=fabs(a-b);
        divisor+=fabs(a)+fabs(b);

    }
    result = dividendo/divisor;
    return (std::isnan(result) ? 0 : result);
}
