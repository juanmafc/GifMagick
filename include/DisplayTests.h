#ifndef DISPLAYTESTS_H
#define DISPLAYTESTS_H

#include "Picture.h"
#include "Screen.h"
#include "Clock.h"
#include "Gif.h"
#include <stdio.h>

class DisplayTests
{
    public:
        DisplayTests();
        virtual ~DisplayTests();

        static void displayASingleImage();
        static void displayTwoImages();
        static void displayATwoFramesGifOneTime();
        static void displayATwoFramesLoopedGif();

    protected:

    private:
};

#endif // DISPLAYTESTS_H
