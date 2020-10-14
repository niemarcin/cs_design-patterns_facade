#pragma once

#include <iostream>
#include <string>
#include <vector>

void Log(std::string msg) {
    std::cout << msg << '\n';
}

enum class ColorSpace {
    RGB, BGR, YMCA, FunnyCats
};

class Image {
public:
    Image() { Log("Image"); }
    std::vector<int> data_;
};

class ImageMetadata {
private:
    std::vector<std::string> imgInfo_;
};

class PngImageMetadata : public ImageMetadata {
public:
    PngImageMetadata(){ Log("PngImageMetadata"); }

private:
    std::vector<std::string> pngImgInfo_;
};

class JpgImageMetadata : public ImageMetadata {
public:
    JpgImageMetadata(ImageMetadata data){ Log("JpgImageMetadata"); }

private:
    std::vector<std::string> jpgImgInfo_;
};

class ImageReader {
public:
    ImageReader() { Log("ImageReader"); }
    //big and complicated class
};

class PngImageReader : public ImageReader {
public:
    PngImageReader(std::string pathToImage) { Log("PngImageReader"); }
    
    PngImageMetadata getPngMetadata() const { return metadata_; }
    Image readRawData() const { return img_; }

private:
    Image img_;
    PngImageMetadata metadata_;
};

class ImageConverter {
public:
    ImageConverter(Image img, ImageMetadata metadata){ Log("ImageConverter"); }
    ImageMetadata generateMetadata() {
        Log("generateMetadata");
        ImageMetadata metadata;
        return metadata;
    }
    void setColorSpace(ColorSpace colors){ Log("setColorSpace"); }
    void saveJpgFile(std::string outputPath){ Log("saveJpgFile"); }

private:
    ColorSpace colors_;
};
