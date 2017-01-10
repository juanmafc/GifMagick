#ifndef DISPLAYTESTS_H
#define DISPLAYTESTS_H

#include "Picture.h"
#include "Screen.h"
#include "Clock.h"
#include "Gif.h"
#include "MainController.h"
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
        static void displayALoopedGifUsingMainController();

    protected:

    private:
        static Picture* getFrameEnBaseELTIempo(Gif* gif, double seconds);
};

#endif // DISPLAYTESTS_H
