//
// Created by potter on 9/12/18.
//

#include "DihedralAngleMetric.h"

double DihedralAngleMetric::metricValue(BinaryMetric *metric, OBAtom *atom_a, OBAtom *atom_b,
                                        OBAtom *atom_c,OBAtom *atom_d) {

    OpenBabel::vector3 coords_a = atom_a->GetVector();
    OpenBabel::vector3 coords_b = atom_b->GetVector();
    OpenBabel::vector3 coords_c = atom_c->GetVector();
    OpenBabel::vector3 coords_d = atom_d->GetVector();

    OpenBabel::vector3 coords_ab = coords_a-coords_b;
    OpenBabel::vector3 coords_dc = coords_d-coords_c;
}
