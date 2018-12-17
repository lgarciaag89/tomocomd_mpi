//
// Created by potter on 13/12/18.
//

#include "GenMatrixQuaterns.h"

void GenMatrixQuaterns::createNSMatrix(OBMol *mol, QuaternMetric* metric, bool isAddH,
                                       bool isLonePair, bool isDistanceCenter, std::string molFilename,
                                       bool isHardSoftSelected){
    if(mol){
        OBAtom *a1, *a2, *a3, *a4;
        int num_mols = mol->NumAtoms();

//        this->diagonalValues = LonePairDistanceCenter(molFilename, isHardSoftSelected, isAddH, isLonePair, isDistanceCenter, metric->distanceMetric);

        for(auto i = 1u; i <= num_mols; i++){
            a1 = mol->GetAtom(i);
            if(!isAddH && a4->IsHydrogen()) continue;

            for(auto j = i+1; j <= num_mols; j++){
                a2 = mol->GetAtom(j);
                if(!isAddH && a3->IsHydrogen()) continue;

                for(auto k = j+1; k <= num_mols ; k++){
                    a3 = mol->GetAtom(k);
                    if(!isAddH && a1->IsHydrogen()) continue;

                    for(auto l = k+1; l <= num_mols; l++){
                        a4 = mol->GetAtom(l);
                        if(!isAddH && a2->IsHydrogen()) continue;

                        matrix.coeffRef(i,j,k,l) = metric->metricValue(a1,a2,a3,a4);
                    }
                }
            }
        }
    }
}