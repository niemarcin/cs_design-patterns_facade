#pragma once
#include "hugeLibrary.hpp"
#include <string>

class Facade {
public:
    Facade(std::string pathToFile) {
        PngImageReader imgReader(pathToFile);
        imgMetadata = imgReader.getPngMetadata();
        rawImg = imgReader.readRawData();
    }
    
    void convertToJpg(std::string outputFile, ColorSpace colors) {
        ImageConverter imgConverter(rawImg, imgMetadata);
        JpgImageMetadata jpgMetadata(imgConverter.generateMetadata());
        imgConverter.setColorSpace(ColorSpace::RGB);
        imgConverter.saveJpgFile(outputFile);
    }

private:
    Image rawImg;
    PngImageMetadata imgMetadata;
};
