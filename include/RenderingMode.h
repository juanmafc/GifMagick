#ifndef RENDERINGMODE_H
#define RENDERINGMODE_H

#include "allegro5/allegro.h"
#include "Screen.h"
#include "Gif.h"


class RenderingMode
{
    public:
        RenderingMode(Screen* screen, Gif* gif);
        virtual ~RenderingMode();

        virtual void render() = 0;

        virtual void handleEvent(ALLEGRO_EVENT* event);

        bool isClosed();

        bool needsRendering();


    protected:
        bool closed;
        bool redraw;

        Screen* screen;
        Gif* gif;

    private:

};

#endif // RENDERINGMODE_H
