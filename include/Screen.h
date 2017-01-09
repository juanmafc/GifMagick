#ifndef SCREEN_H
#define SCREEN_H

#include "Picture.h"
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

class Screen
{
    public:
        Screen(int columns, int rows);
        virtual ~Screen();
        void displayPicture(Picture* picture);

        ALLEGRO_DISPLAY* getDisplay();

    protected:

    private:
        ALLEGRO_DISPLAY * display;

        int rows;
        int columns;

        void copyPixelsToScreenBuffer(Picture* picture);
        void updateScreen();
};

#endif // SCREEN_H
