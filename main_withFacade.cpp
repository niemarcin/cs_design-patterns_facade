#include "facade.hpp"
#include <string>

int main() {
    std::string pathToImage = "path/to/png/image";
    std::string outputFile = "path/to/output/jpg/image";

    Facade facade(pathToImage);
    facade.convertToJpg(outputFile, ColorSpace::RGB);

    return 0;
}
