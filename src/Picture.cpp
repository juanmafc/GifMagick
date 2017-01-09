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
    this->renderImage();
}


Picture::Picture(Magick::Image* image) {
    this->image = image;
    this->renderImage();
}


void Picture::renderImage() {
    //TODO: IMPORTANTE PARA QUE ESTO FUNCIONE ALLEGRO DEBE SER INICIALIZADO ANTES
    this->renderedImage = al_create_bitmap(this->getColumns(), this->getRows());
    al_set_target_bitmap( this->getRenderedImage() );
    for (int row = 0; row < this->getRows(); row++){
        for (int column = 0; column < this->getColumns(); column++){
            float red = this->getRedAt(row, column);
            float green = this->getGreenAt(row, column);
            float blue = this->getBlueAt(row, column);
            al_put_pixel(column, row, al_map_rgb_f(red, green, blue));
        }
    }
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



ALLEGRO_BITMAP* Picture::getRenderedImage() {
    return this->renderedImage;
}




double Picture::getDuration() {
    return this->image->animationDelay()/100.0;
}



