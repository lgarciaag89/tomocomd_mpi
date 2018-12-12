//
// Created by potter on 4/12/18.
//

#ifndef TOMOCOMD_MPI_CPARSER_H
#define TOMOCOMD_MPI_CPARSER_H

#include <CLI11.hpp>

class CParser {
    private:
        CLI::App app{"MPI implementations of tomocomd:http://tomocomd.com/"};
        std::string path;
        bool split;
    public:
        CParser();
        int parsear(int argc, char **argv);
        std::string getDir();
        bool getSplit();
        std::string getVersion();
};


#endif //TOMOCOMD_MPI_CPARSER_H
