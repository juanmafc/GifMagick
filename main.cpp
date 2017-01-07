#include <stdio.h>
#include <allegro5/allegro.h>
#include "AllegroTutorials.h"
#include "Save_gif.h"
#include "algif5src/algif.h"

#include <Magick++.h>
#include <iostream>

#include "DisplayTests.h"

using namespace std;
using namespace Magick;


int main(int argc,char **argv){
  InitializeMagick("bin/Debug");

  // Construct the image object. Seperating image construction from the
  // the read operation ensures that a failure to read the image file
  // doesn't render the image object useless.

/*
  Image image;
  try {
    // Read a file into image object
    image.read( "logo:" );

    // Crop the image to specified size (width, height, xOffset, yOffset)
    image.crop( Geometry(100,100, 100, 100) );

    // Write the image to a file
    image.write( "logo3.jpg" );
  }
  catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }
*/

  DisplayTests::displayASingleImage();
  DisplayTests::displayTwoImages();






/////////////////////////////////////////////////
//  Picture picture("janna.png");
//  Geometry geom(193,84);
//  ColorRGB color;
//  color.red(1);
//  color.blue(1);
//
//  Image destino(geom, color);
//  destino.modifyImage();
//
//
//  Pixels view(destino);
//  // Set all pixels in region anchored at 38x36, with size 160x230 to green.
//  size_t columns = 193; size_t rows = 84;
//  PixelPacket *pixels = view.get(0,0,columns,rows);
//  /*
//  for ( ssize_t row = 0; row < rows ; ++row )
//        for ( ssize_t column = 0; column < columns ; ++column )
//            *pixels++=green;
//    */
//
//
//    Image janna("janna.png");
//
//
//
//    PixelPacket *jannaPix = janna.getPixels(0,0,193,84);
//    int pixelNro = 0;
//  for (int row = 0; row < 84; row++){
//        for (int column = 0; column < 193; column++){
//            /*
//            float red = picture.getRedAt(row, column);
//            float green = picture.getGreenAt(row, column);
//            float blue = picture.getBlueAt(row, column);
//            */
//
//
//            Color color = jannaPix[193 * row + column];
////            Color color = jannaPix[pixelNro];
//            pixelNro++;
//            //ColorRGB rgb(red, green, blue);
//            //ColorRGB rgb(color);
//            //*pixels++=rgb;
//            *pixels++=color;
//
//            /*
//            Magick::PixelPacket *pixeles= this->image.getPixels(0,0,this->image.columns(),this->image.rows());
//            Magick::Color color = pixeles[this->image.rows() * row + column];
//            Magick::ColorRGB rgb(color);
//*/
//
//        }
//    }
//
//
//    view.sync();
//    destino.write("canvas.bmp");
////////////////////////////////////
  return 0;
}






/*

#include <Magick++.h>
#include <iostream>

using namespace std;
using namespace Magick;

int main(int argc,char **argv)
{
  InitializeMagick(*argv);

  // Construct the image object. Seperating image construction from the
  // the read operation ensures that a failure to read the image file
  // doesn't render the image object useless.
  Image image;
  try {
    // Read a file into image object
    image.read( "logo:" );

    // Crop the image to specified size (width, height, xOffset, yOffset)
    image.crop( Geometry(100,100, 100, 100) );

    // Write the image to a file
    image.write( "logo.png" );
  }
  catch( Exception &error_ )
    {
      cout << "Caught exception: " << error_.what() << endl;
      return 1;
    }
  return 0;
}

*/










/*
int main(int argc, char **argv){
    //AlTutorialBasicDisplay();
    //AlTutorialMaxMinResolutionDisplay();
    //AlTutorialBasicEvents();
    //AlTutorialTimers();
    //AlTutorialBasicBitmap();
    //AlTutorialImageLoading();
    al_init();
    ALGIF_ANIMATION* spookyScary = load("disposeGOAL.gif");
    saveGif("disposeREACHED.gif", spookyScary);
}
*/
