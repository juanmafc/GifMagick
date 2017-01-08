#include "Picture.h"

Picture::Picture(string picturePath) {
    this->image = new Magick::Image();
    try {
        // Read a file into image object
        this->image->read(picturePath);
    }
    catch( Magick::Exception &error_ ) {
        cout << "Caught exception: " << error_.what() << endl;
        return;
    }
}


Picture::Picture(Magick::Image* image) {
    this->image = image;
}


Picture::~Picture() {
    delete this->image;
}



int Picture::getColumns() {
    return this->image->columns();
}

int Picture::getRows() {
    return this->image->rows();
}





//TODO: optimizar esto
float Picture::getRedAt(int row, int column) {
    Magick::PixelPacket *pixeles= this->image->getPixels(0,0,this->image->columns(),this->image->rows());
    Magick::Color color = pixeles[this->image->columns() * row + column];
    Magick::ColorRGB rgb(color);
    return rgb.red();
}

float Picture::getGreenAt(int row, int column) {
    Magick::PixelPacket *pixeles= this->image->getPixels(0,0,this->image->columns(),this->image->rows());
    Magick::Color color = pixeles[this->image->columns() * row + column];
    Magick::ColorRGB rgb(color);
    return rgb.green();
}

float Picture::getBlueAt(int row, int column) {
    Magick::PixelPacket *pixeles= this->image->getPixels(0,0,this->image->columns(),this->image->rows());
    Magick::Color color = pixeles[this->image->columns() * row + column];
    Magick::ColorRGB rgb(color);
    return rgb.blue();
}










