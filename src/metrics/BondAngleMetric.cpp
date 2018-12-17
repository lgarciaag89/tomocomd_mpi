//
// Created by potter on 9/12/18.
//

#include "BondAngleMetric.h"

double BondAngleMetric::metricValue( OBAtom *atom_a, OBAtom *atom_b,
                                    OBAtom *atom_c) {
    OpenBabel::vector3 u = atom_a->GetVector()-atom_b->GetVector();
    OpenBabel::vector3 v = atom_c->GetVector()-atom_b->GetVector();

    double uv = 0.0, mod_u = 0.0, mod_v = 0.0;

    for( int i = 0 ; i < 3 ; i++ ) {
        uv +=u[i] * v[i];
        mod_u+=u[i]*u[i];
        mod_v+=v[i]*v[i];
    }
    mod_u=sqrt(mod_u)*sqrt(mod_v);

    return acos(uv/mod_u);
}