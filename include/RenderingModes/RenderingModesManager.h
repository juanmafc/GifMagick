#ifndef RENDERINGMODESMANAGER_H
#define RENDERINGMODESMANAGER_H

#include "Screen.h"
#include "Gif.h"

#include "LoopedMode.h"
#include "InterpolationMode.h"

class RenderingModesManager
{
    public:
        RenderingModesManager(Screen* screen, Gif* gif);
        virtual ~RenderingModesManager();

        RenderingMode* getCurrentMode(ALLEGRO_EVENT* event);
        RenderingMode* getCurrentMode();

    protected:

    private:
        RenderingMode* currentMode;

        LoopedMode* loopedMode;
        InterpolationMode* interpolMode;

        void setNextMode();


};

#endif // RENDERINGMODESMANAGER_H
