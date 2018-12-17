//
// Created by potter on 9/12/18.
//

#include "PyramidVolumeMetric.h"


double PyramidVolumeMetric::metricValue(OBAtom *atom_a, OBAtom *atom_b,
                                        OBAtom *atom_c,OBAtom *atom_d){
    OpenBabel::vector3 coords_a = atom_a->GetVector();
    OpenBabel::vector3 coords_b = atom_b->GetVector();
    OpenBabel::vector3 coords_c = atom_c->GetVector();
    OpenBabel::vector3 coords_d = atom_d->GetVector();

    double ab_0 = coords_a[0]-coords_b[0];
    double ac_0 = coords_a[0]-coords_c[0];
    double ad_0 = coords_a[0]-coords_d[0];

    double ab_1 = coords_a[1]-coords_b[1];
    double ac_1 = coords_a[1]-coords_c[1];
    double ad_1 = coords_a[1]-coords_d[1];

    double ab_2 = coords_a[2]-coords_b[2];
    double ac_2 = coords_a[2]-coords_c[2];
    double ad_2 = coords_a[2]-coords_d[2];

    double sum = ab_0*ac_1*ad_2+ab_1*ac_2*ad_0+ab_2*ac_0*ad_1;
    double rest = ab_2*ac_1*ad_0+ab_1*ac_0*ad_2+ab_0*ac_2*ad_1;
    double result = (sum-rest)/6;
    return result;
}