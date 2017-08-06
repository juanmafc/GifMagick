#ifndef INTERPOLATIONMODE_H
#define INTERPOLATIONMODE_H

#include <RenderingModes/RenderingMode.h>
#include <map>
#include "InterpolationMethods/LinearInterpolation.h"


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
        void registerMouseClick(int x, int y);

        int currentMouseX;
        int currentMouseY;
        Picture* pic;

};

#endif // INTERPOLATIONMODE_H
