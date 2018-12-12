//
// Created by potter on 4/12/18.
//

#include "CParser.h"

CParser::CParser() {
    split = false;
    path = "";
    CLI::Option *opt_d = app.add_option("-p,--path", path, "Directory path base")->required()->check(CLI::ExistingDirectory);
    CLI::Option *opt_s = app.add_flag("-s,--split", split, "perform splitting of the input(optional argument)");
    CLI::Option *opt_v = app.add_flag("--version", "Get version");
}
int CParser::parsear(int argc, char **argv) {
    CLI11_PARSE(app, argc, argv);
}

std::string CParser::getDir() {
    return path;
}

bool CParser::getSplit() {
    return split;
}

std::string CParser::getVersion() {
    return "0.1b";
}