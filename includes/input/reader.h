//
// Created by potter on 2/12/18.
//

#ifndef TOMOCOMD_MPI_READER_H
#define TOMOCOMD_MPI_READER_H

#endif //TOMOCOMD_MPI_READER_H


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <boost/filesystem.hpp>

#include <openbabel/obconversion.h>
#include <openbabel/mol.h>

#define MOLS_FOLDER "mols"
#define SDFS_FOLDER "sdfs"
#define PROJECTS_FOLDER "projects"

using namespace OpenBabel;

class Reader{
private:
    std::string basedir;
    std::vector<std::string> sdfs;
    std::vector<std::string> mols;
    std::vector<std::string> projects;
    void split_sdfs();
    void split_sdfs(std::string file_sdf);
public:
    Reader(std::string base);
    void read_mols();
    void read_sdfs();
    void read_project();

    void show();
};