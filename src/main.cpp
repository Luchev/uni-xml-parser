#include <src/XmlBuilder.h>
#include <include/XmlElements.h>
#include <iostream>

void run(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not enough parameters";
        return;
    }
    XmlBuilder builder;
    std::string file = argv[1];
    XmlElementDefault* root = builder.parseFile(file);
    std::cout << root->toStringBeautified();
    delete root;
}

int main(int argc, char* argv[]) {
    run(argc, argv);
    return 0;
}
