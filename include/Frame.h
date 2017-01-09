#ifndef FRAME_H
#define FRAME_H

#include <Picture.h>


class Frame : public Picture
{
    public:
        Frame(Magick::Image* image);
        virtual ~Frame();

        double getDuration();
    protected:

    private:
};

#endif // FRAME_H
