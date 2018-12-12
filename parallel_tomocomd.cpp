#include <iostream>

#include <reader.h>
#include <CParser.h>
#include <mpi.h>
#include <openbabel/atom.h>
#include <ChebyshevMetric.h>
#include <LanceWilliamsMetric.h>
#include <ClarkMetric.h>
#include <SoergelMetric.h>
#include <BhattacharyyaMetric.h>
#include <WaveEdgesMetric.h>
#include <AngularSeparationMetric.h>
#include <EuclidianMetric.h>
#include "CanberraMetric.h"
#include "MinkowskiMetric.h"
#include "PerimeterTernaryMetric.h"
#include "PyramidVolumeMetric.h"
#include <ManhattanMetric.h>
#include <SumaTwoSides.h>
#include <BondAngleMetric.h>



int main(int argc, char **argv) {

//    int ierr, cthreads, id;
//    ierr = MPI_Init(&argc, &argv);
//
//    if (ierr != 0) {
//        std::cout << "  MPI_Init returned nonzero.\n";
//        exit(1);
//    }
//    MPI_Comm_size(MPI_COMM_WORLD, &cthreads);
//
//    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    CParser parser;
    parser.parsear(argc, argv);
    std::string base = parser.getDir();
    Reader *r;

    vector3 v1 = {4,3,5};
    OBAtom atom1 = OBAtom();
    atom1.SetVector(v1);

    vector3 v2 = {1,3,2};
    OBAtom atom2 = OBAtom();
    atom2.SetVector(v2);

    vector3 v3 = {6,8,7};
    OBAtom atom3 = OBAtom();
    atom3.SetVector(v3);

    vector3 v4 = {14,16,20};
    OBAtom atom4 = OBAtom();
    atom4.SetVector(v4);

    CanberraMetric cam;
    std::cout<<"Camberra: "<<cam.metricValue(atom1,atom2)<<std::endl;

    MinkowskiMetric min = MinkowskiMetric(2);
    std::cout<<"Minkowski: "<<min.metricValue(atom1,atom2)<<std::endl;

    ChebyshevMetric che;
    std::cout<<"Chebyshev: "<<che.metricValue(atom1,atom2)<<std::endl;

    LanceWilliamsMetric lan;
    std::cout<<"LanceWilliams: "<<lan.metricValue(atom1,atom2)<<std::endl;

    ClarkMetric cla;
    std::cout<<"ClarkMetric: "<<cla.metricValue(atom1,atom2)<<std::endl;

    SoergelMetric soe;
    std::cout<<"SoergelMetric: "<<soe.metricValue(atom1,atom2)<<std::endl;

    BhattacharyyaMetric bha;
    std::cout<<"BhattacharyyaMetric: "<<bha.metricValue(atom1,atom2)<<std::endl;

    WaveEdgesMetric wav;
    std::cout<<"WaveEdgesMetric: "<<wav.metricValue(atom1,atom2)<<std::endl;

    AngularSeparationMetric ang;
    std::cout<<"AngularSeparationMetric: "<<ang.metricValue(atom1,atom2)<<std::endl;

    EuclidianMetric euc;
    std::cout<<"EuclidianMetric: "<<euc.metricValue(atom1,atom2)<<std::endl;

    ManhattanMetric man1;
    std::cout<<"ManhattanMetric: "<<man1.metricValue(atom1,atom2)<<std::endl;

    SumaTwoSides sum;
    EuclidianMetric *euc1 = new EuclidianMetric;
    BinaryMetric *bin = euc1;
    std::cout<<"SumaTwoSides with EuclidianMetric: "<<sum.metricValue(bin,atom1,atom2,atom3)<<std::endl;

    PerimeterTernaryMetric per;
    std::cout<<"PerimeterMetric with EuclidianMetric: "<<per.metricValue(bin,atom1,atom2,atom3)<<std::endl;

    PyramidVolumeMetric pyr;
    std::cout<<"PyramidVolumeMetric with EuclidianMetric: "<<pyr.metricValue(bin,atom1,atom2,atom3, atom4)<<std::endl;

    BondAngleMetric bond;
    std::cout<<"BondAngleMetric with EuclidianMetric: "<<bond.metricValue(bin,atom1,atom2,atom3)<<std::endl;
//    if (base == "") {
//        if (id == 0)
//            std::cout << std::endl << "Usage:\n" + std::string(argv[0]) + " [-s/--split] -p/--path base_path"
//                      << std::endl;
//        MPI_Finalize();
//        return 0;
//    }

//    r = new Reader(base);
//    bool split = parser.getSplit();

//    if (id == 0) {
//        bool split = parser.getSplit();
//        if (split) {
//            try {
//                r->read_sdfs();
//            } catch (const std::runtime_error &er) {
//                std::cerr << er.what() << std::endl;
//                MPI_Abort(MPI_COMM_WORLD,1);
//                MPI_Finalize();
//                return 0;
//            }
//        }
//    }
//
//
//    MPI_Barrier(MPI_COMM_WORLD);
//
//    r->read_mols();
//    r->read_project();

//MPI_Finalize();
    return 0;
}