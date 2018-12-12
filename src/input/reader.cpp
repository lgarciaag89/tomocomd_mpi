//
// Created by potter on 2/12/18.
//

#include "reader.h"

Reader::Reader(std::string base) {g

    if (base[base.size() - 1] != '/')
        base.push_back('/');

    basedir = base;

    if (!boost::filesystem::is_directory(basedir))
        throw std::runtime_error(basedir + " is not a directoy");

    if (!boost::filesystem::exists(basedir + SDFS_FOLDER))
        throw std::runtime_error(basedir + SDFS_FOLDER + " no exist, please add almost one sdf file");
    if (!boost::filesystem::exists(basedir + MOLS_FOLDER))
        boost::filesystem::create_directories(basedir + MOLS_FOLDER);
}

void Reader::read_sdfs() {
    boost::filesystem::path p(basedir + SDFS_FOLDER);

    boost::filesystem::directory_iterator end_itr;

    for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr) {
        if (boost::filesystem::is_regular_file(itr->path())) {
            std::string current_file = itr->path().string();
            std::string ext = current_file.substr(current_file.size() - 3, 3);
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
            std::string name_sdf = current_file.substr(current_file.rfind('/') + 1);
            if (ext.compare("sdf") == 0) {
                split_sdfs(current_file);
                sdfs.push_back(current_file);
                std::cout << name_sdf + " sdf file readed" << std::endl;
            }
        }
    }
}

void Reader::split_sdfs(std::string file_sdf) {

    OBConversion obconversion;
    obconversion.SetInAndOutFormats("sdf", "mol");
    OBMol mol;

    bool notatend;

    notatend = obconversion.ReadFile(&mol, file_sdf);

    std::string name_sdf = file_sdf.substr(file_sdf.rfind('/') + 1);
    int cont = 0;

    std::cout << "Spliting " + name_sdf << std::endl;
    int num_mols = obconversion.NumInputObjects();
    while (notatend) {
        std::string mol_name = name_sdf + "_" +std::to_string(++cont) + ".mol";
        std::string p = basedir + MOLS_FOLDER + "/" + mol_name;
        if (!obconversion.WriteFile(&mol, p))
            throw std::runtime_error("Parser error: molecule # " + std::to_string(cont) + " on sdf " + name_sdf);
        mols.push_back(mol_name);
        mol.Clear();
        notatend = obconversion.Read(&mol);
    }
    if (cont != num_mols)
        throw std::runtime_error("Parser error: Not all the molecules in " + name_sdf + " sdf file are read");

}

void Reader::split_sdfs() {

    OBConversion obconversion;
    obconversion.SetInAndOutFormats("sdf", "mol");
    OBMol mol;

    bool notatend;

    for (std::string &file_sdf:sdfs) {
        notatend = obconversion.ReadFile(&mol, file_sdf);

        std::string name_sdf = file_sdf.substr(file_sdf.rfind('/') + 1);
        int cont = 0;

        std::cout << "Spliting " + name_sdf << std::endl;
        int num_mols = obconversion.NumInputObjects();
        while (notatend) {
            std::string mol_name = name_sdf +"_" +std::to_string(++cont) + ".mol";
            std::string p = basedir + MOLS_FOLDER + "/" + mol_name;
            if (!obconversion.WriteFile(&mol, p))
                throw std::runtime_error("Parser error: molecule # " + std::to_string(cont) + " on sdf " + name_sdf);
            mols.push_back(mol_name);
            mol.Clear();
            notatend = obconversion.Read(&mol);
        }
        if (cont != num_mols)
            throw std::runtime_error("Parser error: Not all the molecules in " + name_sdf + " sdf file are read");
    }
}

void Reader::read_mols() {
    OBConversion obconversion;
    obconversion.SetInFormat("mol");
    OBMol mol;

    int cantmols = mols.size();
    boost::filesystem::path p(basedir + MOLS_FOLDER);

    boost::filesystem::directory_iterator end_itr;

    for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr) {
        if (boost::filesystem::is_regular_file(itr->path())) {

            std::string current_file = itr->path().string();

            // extrae la extencion del fichero actual

            std::string ext = current_file.substr(current_file.size() - 3, 3);
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

            if (ext.compare("mol") == 0) {

                // extrae el nombre del fichero y pregunta si ya esta en el cjto de moleculas
                std::string name_mol = current_file.substr(current_file.rfind('/') + 1);
                if( std::find(mols.begin(), mols.end(), name_mol) == mols.end() )
                {
                    if(obconversion.ReadFile(&mol, current_file)){
                        mols.push_back(name_mol);
                        cantmols++;
                    }
                    else
                        std::cerr <<"The "+name_mol+" molecule was not read ";
                    mol.Clear();
                }
            }
        }
    }
    std::cout << std::to_string(cantmols)+" molecules have been read" << std::endl;
}

void Reader::read_project() {
    boost::filesystem::path p(basedir + PROJECTS_FOLDER);

    boost::filesystem::directory_iterator end_itr;

    for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr) {
        if (boost::filesystem::is_regular_file(itr->path())) {
            std::string current_file = itr->path().string();
            std::string ext = current_file.substr(current_file.size() - 3, 3);
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
            std::string name_project = current_file.substr(current_file.rfind('/') + 1);
            if (ext.compare("xml") == 0) {
                projects.push_back(current_file);
                std::cout << "Project " + name_project+" readed" << std::endl;
            }
        }
    }
}

void Reader::show() {
    std::cout << basedir << std::endl;
    for (std::string &dir:sdfs)
        std::cout << dir << std::endl;
}