#ifndef IMAGEMAGICKTESTS_H
#define IMAGEMAGICKTESTS_H

#include "Magick++.h"
#include "Picture.h"
#include "Screen.h"
#include "Gif.h"
#include <vector>

using namespace std;
using namespace Magick;

class ImageMagickTests
{
    public:
        ImageMagickTests();
        virtual ~ImageMagickTests();

        static void coalesceImagesTest();
        static void pixelHandlingTest();
        static void renderAPictureIntoAnotherPicture();
        static void saveAGif();
        static void editAndSaveGifTest();

    protected:

    private:
};

#endif // IMAGEMAGICKTESTS_H
