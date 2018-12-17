#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Metric.h"
#include "PyramidVolumeMetric.h"
#include "SumaTwoSides.h"
#include "EuclidianMetric.h"
#include "AngularSeparationMetric.h"

#include <openbabel/mol.h>
#include <openbabel/obconversion.h>
#include <SymMatrix.h>
#include <GenMatrixTriples.h>
#include <PerimeterTernaryMetric.h>

using namespace OpenBabel;

int main(int argc, char **argv) {

    int *a = new int;
    *a = 5;


    BinaryMetric *bin = new EuclidianMetric;
    OBConversion obconversion;
    obconversion.SetInFormat("mol");
    OBMol mol;

    obconversion.ReadFile(&mol, "/media/DATA/05-WORKSPACE/ClionProjects/mi_tomocomd/data/pruebaTOMOCOM/mols/OTAVA_PrimScreen15_Modified_200.sdf_1.mol");

    std::cout<<mol.NumAtoms()<<std::endl;

    SymMatrix sym(mol.NumAtoms());


    sym.createNSMatrix(&mol,bin,0, 0,0,"",0);

    sym.show();

    GenMatrixTriples mtrix(mol.NumAtoms());
    TernaryMetric *tmetric = new PerimeterTernaryMetric(bin);
    mtrix.createNSMatrix(&mol, tmetric,0, 0, 0,"", 0);
    return 0;
}