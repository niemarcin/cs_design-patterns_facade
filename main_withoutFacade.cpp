#include "hugeLibrary.hpp"
#include <string>

int main() {
    std::string pathToImage = "path/to/png/image";
    std::string outputFile = "path/to/output/jpg/image";
    
    PngImageReader imgReader(pathToImage);
    PngImageMetadata imgMetadata = imgReader.getPngMetadata();
    Image rawImg = imgReader.readRawData();
    ImageConverter imgConverter(rawImg, imgMetadata);
    JpgImageMetadata jpgMetadata(imgConverter.generateMetadata());
    imgConverter.setColorSpace(ColorSpace::RGB);
    imgConverter.saveJpgFile(outputFile);

    return 0;
}
