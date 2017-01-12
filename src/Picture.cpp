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
    al_destroy_bitmap(this->renderedImage);
}



int Picture::getColumns() {
    return this->image->columns();
}

int Picture::getRows() {
    return this->image->rows();
}





//TODO: optimizar y refactprozar esto
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


Magick::Image* Picture::getImage() {
    return this->image;
}





void Picture::drawPicture(Picture* picture, int x, int y) {
    al_set_target_bitmap(this->getRenderedImage());
    al_draw_bitmap( picture->getRenderedImage(),x, y, 0);
    al_flip_display();
}



void Picture::save(string picturePath) {
    this->unrenderImage();
    this->image->write(picturePath);
}


void Picture::unrenderImage() {
    //TODO: IMPORTANTE PARA QUE ESTO FUNCIONE ALLEGRO DEBE SER INICIALIZADO ANTES
    //POR ALGUNA RAZON NO FUNCIONA ESTO, rta: era por el orden, primero setear el type y despues getear los pixeles
    this->image->modifyImage();
    this->image->type(Magick::TrueColorType);
    //TODO: podria refactorizarse, aparecen como 4 veces estas lineas...
    Magick::PixelPacket *pixeles= this->image->getPixels(0,0,this->image->columns(),this->image->rows());

    for (int row = 0; row < this->getRows(); row++){
        for (int column = 0; column < this->getColumns(); column++){
            ALLEGRO_COLOR renderedColor = al_get_pixel(this->getRenderedImage(), column, row);
            float red = renderedColor.r;
            float green = renderedColor.g;
            float blue = renderedColor.b;

            pixeles[this->getColumns() * row + column] = Magick::ColorRGB(red, green, blue);
        }
    }
    this->image->syncPixels();
}
