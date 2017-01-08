#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <string>
#include <Magick++.h>

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;

class Picture
{
    public:
        Picture(string picturePath);
        Picture(Magick::Image* image);
        virtual ~Picture();

        int getColumns();
        int getRows();


        ALLEGRO_BITMAP* getRenderedImage();

        float getRedAt(int row, int column);
        float getGreenAt(int row, int column);
        float getBlueAt(int row, int column);

    protected:

    private:
        Magick::Image* image;
        ALLEGRO_BITMAP* renderedImage;

        void renderImage();
};

#endif // PICTURE_H
