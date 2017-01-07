#ifndef IMAGEMAGICKTESTS_H
#define IMAGEMAGICKTESTS_H

#include "Magick++.h"
#include "Picture.h"
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

    protected:

    private:
};

#endif // IMAGEMAGICKTESTS_H
