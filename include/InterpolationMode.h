#ifndef INTERPOLATIONMODE_H
#define INTERPOLATIONMODE_H

#include <RenderingMode.h>
#include <map>
#include "LinearInterpolation.h"


using namespace std;

class InterpolationMode : public RenderingMode
{
    public:
        InterpolationMode(Screen* screen, Gif* gif);
        virtual ~InterpolationMode();

        void render();

        virtual void handleEvent(ALLEGRO_EVENT* event);

    protected:
        int currentFrame;
        map<int, Point> clickedPoints;
        void interpolateGif();

    private:

};

#endif // INTERPOLATIONMODE_H
