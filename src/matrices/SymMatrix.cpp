//
// Created by potter on 12/12/18.
//


#include "SymMatrix.h"

void SymMatrix::createNSMatrix(OBMol *mol, BinaryMetric* metric, bool isAddH, bool isLonePair, bool isDistanceCenter,
                               std::string molFilename, bool isHardSoftSelected){
    if (mol) {
        OBAtom *a1, *a2;
        unsigned int col,row, num_atoms = mol->NumAtoms() ;

//        double *diagonalValues = LonePairDistanceCenter(molFilename, isHardSoftSelected, isAddH, isLonePair, isDistanceCenter, metric);

        for (row = 1 ; row <=  num_atoms ; row++) {
            a1 = mol->GetAtom(row);
            if (!isAddH && a1->IsHydrogen())
                continue;
            for (unsigned int col = row+1; col <=num_atoms ; col++) {
                a2 = mol->GetAtom(col);
                if (!isAddH && a2->IsHydrogen()){
                    continue;
                }
                this->set(row-1, col-1, metric->metricValue(a1,a2));
            }
        }
//        delete[] diagonalValues;
    }
}

void SymMatrix::set(int row, int col, double value) {
    if(row >= size )
        throw new std::out_of_range("row "+std::to_string(row)+" out of range");
    if(col >= size )
        throw new std::out_of_range("column "+std::to_string(col)+" out of range");

    matrix.coeffRef(row,col) = value;
}

double SymMatrix::get(int row, int col) {
    if(row >= size )
        throw new std::out_of_range("row "+std::to_string(row)+" out of range");
    if(col >= size )
        throw new std::out_of_range("column "+std::to_string(col)+" out of range");
    return matrix.coeff(row,col);
}

void SymMatrix::show() {
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%.2f ",matrix.coeff(i,j));
        }
        std::cout<<std::endl;
    }

}
