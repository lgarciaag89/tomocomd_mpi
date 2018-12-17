//
// Created by potter on 9/12/18.
//

#include "AngularSeparationMetric.h"


double AngularSeparationMetric::metricValue(OBAtom *atom_a, OBAtom *atom_b){
    OpenBabel::vector3 coords_a = atom_a->GetVector();
    OpenBabel::vector3 coords_b = atom_b->GetVector();

    double result = 0.0, dividendo = 0, divisor = 0;
    double sum_x = 0.0, sum_y = 0.0;
    for(int i= 0; i < 3 ; i++){
        double a = coords_a[i],b = coords_b[i];
        dividendo+=a*b;
        sum_x+=a*a;
        sum_y+=b*b;
    }
    divisor=sqrt(sum_x*sum_y);
    result = dividendo/divisor;
    return (std::isnan(result) ? 0 : 1-result);
}