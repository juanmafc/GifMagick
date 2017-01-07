#include "ImageMagickTests.h"


ImageMagickTests::ImageMagickTests()
{
    //ctor
}

ImageMagickTests::~ImageMagickTests()
{
    //dtor
}


void ImageMagickTests::coalesceImagesTest() {
    vector<Image> imagenes;
    vector<Image> imagenesCoalesceadas;

    readImages(&imagenes, "buckleupTeddy.gif");
    //readImages(&imagenes, "disposeGOAL.gif");
    //readImages(&imagenes, "francella.gif");

    //coalesceImages(&imagenesCoalesceadas, imagenes.begin(), imagenes.end() );
    coalesceImages(&imagenes, imagenes.begin(), imagenes.end() );

    Image appended;
    //appendImages( &appended, imagenesCoalesceadas.begin(), imagenesCoalesceadas.end() );
    appendImages( &appended, imagenes.begin(), imagenes.end() );
    appended.write( "undertaker.png" );
}





void ImageMagickTests::pixelHandlingTest() {
    Picture picture("janna.png");
    Geometry geom(193,84);
    ColorRGB color;
    color.red(1);
    color.blue(1);

    Image destino(geom, color);
    destino.modifyImage();


    Pixels view(destino);
    // Set all pixels in region anchored at 38x36, with size 160x230 to green.
    size_t columns = 193; size_t rows = 84;
    PixelPacket *pixels = view.get(0,0,columns,rows);
    /*
    for ( ssize_t row = 0; row < rows ; ++row )
            for ( ssize_t column = 0; column < columns ; ++column )
                *pixels++=green;
        */


    Image janna("janna.png");
    PixelPacket *jannaPix = janna.getPixels(0,0,193,84);
    int pixelNro = 0;
    for (int row = 0; row < 84; row++){
        for (int column = 0; column < 193; column++){
            /*
            float red = picture.getRedAt(row, column);
            float green = picture.getGreenAt(row, column);
            float blue = picture.getBlueAt(row, column);
            */
            Color color = jannaPix[193 * row + column];
    //      Color color = jannaPix[pixelNro];
            pixelNro++;
            //ColorRGB rgb(red, green, blue);
            //ColorRGB rgb(color);
            //*pixels++=rgb;
            *pixels++=color;
            /*
            Magick::PixelPacket *pixeles= this->image.getPixels(0,0,this->image.columns(),this->image.rows());
            Magick::Color color = pixeles[this->image.rows() * row + column];
            Magick::ColorRGB rgb(color);
    */
        }
    }
    view.sync();
    destino.write("canvas.bmp");
}







