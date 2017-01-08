#ifndef DISPLAYTESTS_H
#define DISPLAYTESTS_H

#include "Picture.h"
#include "Screen.h"
#include "Gif.h"

class DisplayTests
{
    public:
        DisplayTests();
        virtual ~DisplayTests();

        static void displayASingleImage();
        static void displayTwoImages();
        static void displayATwoFramesGifOneTime();

    protected:

    private:
};

#endif // DISPLAYTESTS_H
