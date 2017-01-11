#include <stdio.h>
#include <allegro5/allegro.h>
#include "AllegroTutorials.h"
#include "Save_gif.h"
#include "algif5src/algif.h"

#include <Magick++.h>
#include <iostream>

#include "DisplayTests.h"
#include "ImageMagickTests.h"
#include "InterpolationTests.h"

#include <vector>

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




    //ImageMagickTests::coalesceImagesTest();
    //ImageMagickTests::pixelHandlingTest();


    //DisplayTests::displayASingleImage();
    //DisplayTests::displayTwoImages();
    //DisplayTests::displayATwoFramesGifOneTime();
    //DisplayTests::displayATwoFramesLoopedGif();
    //DisplayTests::displayALoopedGifUsingMainController();
    DisplayTests::navigateAGifFrameByFrame();

    //InterpolationTests::getMouseCoordinatesOnClick();
    //InterpolationTests::linearInterpolationTest();


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



/*
    vector<Image> frames;
    readImages(&frames, "buckleupTeddy.gif");
    coalesceImages(&frames, frames.begin(), frames.end());

    list<Image> myFrames;
    myFrames.push_back(frames[0]);
    myFrames.push_back(frames[9]);

    writeImages(myFrames.begin(), myFrames.end(), "twoFrames.gif");
*/
