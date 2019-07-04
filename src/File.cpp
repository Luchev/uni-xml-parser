#include <src/File.h>
#include <fstream>

std::string File::readFileToString(const std::string & fileName) {
    std::ifstream inputFile(fileName, std::ios_base::binary);
    std::string contents;
    if (inputFile.fail()) {
        return contents;
    }

    if (inputFile.is_open()) {
        char next;
        while (inputFile.get(next)) {
            contents.push_back(next);
        }
    }
    return contents;
}
