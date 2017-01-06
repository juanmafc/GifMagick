#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <string>
#include <Magick++.h>

using namespace std;

class Picture
{
    public:
        Picture(string picturePath);
        virtual ~Picture();

        float getRedAt(int row, int column);
        float getGreenAt(int row, int column);
        float getBlueAt(int row, int column);

    protected:

    private:
        Magick::Image image;
};

#endif // PICTURE_H
