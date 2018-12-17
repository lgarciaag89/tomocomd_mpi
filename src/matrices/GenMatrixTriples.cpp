//
// Created by potter on 12/12/18.
//


#include "GenMatrixTriples.h"

void GenMatrixTriples::createNSMatrix(OBMol *mol, TernaryMetric* metric, bool isAddH, bool isLonePair, bool isDistanceCenter,
                                      std::string molFilename, bool isHardSoftSelected){
    if(mol){
        OBAtom *a1, *a2, *a3;
        int r = 0, c = 0, rr = 0, num_atoms = mol->NumAtoms();

//        this->diagonalValues = LonePairDistanceCenter(molFilename, isHardSoftSelected, isAddH, isLonePair, isDistanceCenter, metric->distanceMetric);
        for(auto i = 1u; i <= num_atoms; i++){
            a1 = mol->GetAtom(i);
            if(!isAddH && a3->IsHydrogen()) continue;

            for(auto j = i+1; j <= num_atoms; j++){
                a2 = mol->GetAtom(j);
                if(!isAddH && a1->IsHydrogen()) continue;

                for(auto k = 1u; k <= num_atoms ; k++){
                    a3 = mol->GetAtom(k);
                    if(!isAddH && a2->IsHydrogen()) continue;

                    matrix.coeffRef(i,j,k) = metric->metricValue(a1,a2,a3);

                }
            }
        }
    }
}