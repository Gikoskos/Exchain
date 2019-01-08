#include "utilities/files.h"
#include <iostream>
#include <fstream>
#include <cerrno>

int file_to_string(std::string fname,
                   std::string& fcontents)
{
    std::ifstream file_in(fname, std::ios::in | std::ios::binary);

    if (!file_in) {
        return errno;
    }

    file_in.seekg(0, std::ios::end);
    fcontents.resize(file_in.tellg());

    file_in.seekg(0, std::ios::beg);
    file_in.read(&fcontents[0], fcontents.size());

    file_in.close();

    return 0;
}
