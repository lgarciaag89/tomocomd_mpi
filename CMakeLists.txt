cmake_minimum_required(VERSION 3.8.2)
project(tomocomd_mpi)

set(CMAKE_CXX_STANDARD 11)

# set the module path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

# find and setup openbabel
find_package(OpenBabel REQUIRED)
if(OPENBABEL_FOUND)
    message(STATUS "OPENBABEL_INCLUDE_DIRS: ${OPENBABEL_INCLUDE_DIRS}")
    message(STATUS "OPENBABEL_LIBRARIES: ${OPENBABEL_LIBRARIES}")
    include_directories(${OPENBABEL_INCLUDE_DIRS})

endif()

find_package(Boost 1.62 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

find_package(MPI REQUIRED)
if(MPI_FOUND)

    message(STATUS "MPI_CXX_INCLUDE_PATH: ${MPI_CXX_INCLUDE_PATH}")
    message(STATUS "MPI_CXX_LIBRARIES: ${MPI_CXX_LIBRARIES}")
    message(STATUS "MPI_CXX_COMPILER: ${MPI_CXX_COMPILER}")
    set(CMAKE_CXX_COMPILER ${MPI_CXX_COMPILER})
    include_directories(${MPI_INCLUDE_PATH})

endif()

include_directories(includes/input includes/utils includes/metrics )
message("sources ${CMAKE_SOURCE_DIR}")
set(SOURCE_FILES parallel_tomocomd.cpp includes/utils/CLI11.hpp src/utils/CParser.cpp includes/utils/CParser.h src/input/reader.cpp includes/input/reader.h src/metrics/Metric.cpp includes/metrics/Metric.h src/metrics/CanberraMetric.cpp includes/metrics/CanberraMetric.h src/metrics/MinkowskiMetric.cpp includes/metrics/MinkowskiMetric.h src/metrics/ChebyshevMetric.cpp includes/metrics/ChebyshevMetric.h src/metrics/LanceWilliamsMetric.cpp includes/metrics/LanceWilliamsMetric.h src/metrics/ClarkMetric.cpp includes/metrics/ClarkMetric.h src/metrics/SoergelMetric.cpp includes/metrics/SoergelMetric.h src/metrics/BhattacharyyaMetric.cpp includes/metrics/BhattacharyyaMetric.h src/metrics/WaveEdgesMetric.cpp includes/metrics/WaveEdgesMetric.h src/metrics/AngularSeparationMetric.cpp includes/metrics/AngularSeparationMetric.h src/metrics/EuclidianMetric.cpp includes/metrics/EuclidianMetric.h src/metrics/ManhattanMetric.cpp includes/metrics/ManhattanMetric.h includes/metrics/BinaryMetric.h src/metrics/PerimeterTernaryMetric.cpp includes/metrics/PerimeterTernaryMetric.h includes/metrics/TernaryMetric.h src/metrics/TriangleAreaMetric.cpp includes/metrics/TriangleAreaMetric.h src/metrics/SumaTwoSides.cpp includes/metrics/SumaTwoSides.h includes/metrics/QuaternMetric.h src/metrics/SumThreeSides.cpp includes/metrics/SumThreeSides.h src/metrics/PerimeterQuaternMetric.cpp includes/metrics/PerimeterQuaternMetric.h src/metrics/PyramidVolumeMetric.cpp includes/metrics/PyramidVolumeMetric.h src/metrics/BondAngleMetric.cpp includes/metrics/BondAngleMetric.h src/metrics/DihedralAngleMetric.cpp includes/metrics/DihedralAngleMetric.h)
add_executable(tomocomd_mpi ${SOURCE_FILES} src/metrics/Metric.cpp includes/metrics/Metric.h src/metrics/CanberraMetric.cpp includes/metrics/CanberraMetric.h src/metrics/MinkowskiMetric.cpp includes/metrics/MinkowskiMetric.h src/metrics/ChebyshevMetric.cpp includes/metrics/ChebyshevMetric.h src/metrics/LanceWilliamsMetric.cpp includes/metrics/LanceWilliamsMetric.h src/metrics/ClarkMetric.cpp includes/metrics/ClarkMetric.h src/metrics/BhattacharyyaMetric.cpp includes/metrics/BhattacharyyaMetric.h src/metrics/WaveEdgesMetric.cpp includes/metrics/WaveEdgesMetric.h src/metrics/AngularSeparationMetric.cpp includes/metrics/AngularSeparationMetric.h src/metrics/EuclidianMetric.cpp includes/metrics/EuclidianMetric.h src/metrics/ManhattanMetric.cpp includes/metrics/ManhattanMetric.h includes/metrics/BinaryMetric.h src/metrics/PerimeterTernaryMetric.cpp includes/metrics/PerimeterTernaryMetric.h includes/metrics/TernaryMetric.h src/metrics/TriangleAreaMetric.cpp includes/metrics/TriangleAreaMetric.h src/metrics/SumaTwoSides.cpp includes/metrics/SumaTwoSides.h includes/metrics/QuaternMetric.h src/metrics/SumThreeSides.cpp includes/metrics/SumThreeSides.h src/metrics/PerimeterQuaternMetric.cpp includes/metrics/PerimeterQuaternMetric.h src/metrics/PyramidVolumeMetric.cpp includes/metrics/PyramidVolumeMetric.h src/metrics/BondAngleMetric.cpp includes/metrics/BondAngleMetric.h src/metrics/DihedralAngleMetric.cpp includes/metrics/DihedralAngleMetric.h)

if(Boost_FOUND)

    target_link_libraries(tomocomd_mpi ${Boost_LIBRARIES})

endif()

if(OPENBABEL_FOUND)

    target_link_libraries(tomocomd_mpi ${OPENBABEL_LIBRARIES})

endif()

if(MPI_FOUND)

    target_link_libraries(tomocomd_mpi ${MPI_CXX_LIBRARIES})

endif()