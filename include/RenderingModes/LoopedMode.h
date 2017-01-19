#ifndef LOOPEDMODE_H
#define LOOPEDMODE_H

#include <RenderingModes/RenderingMode.h>


class LoopedMode : public RenderingMode
{
    public:
        LoopedMode(Screen* screen, Gif* gif);
        virtual ~LoopedMode();

        void render();

        virtual void handleEvent(ALLEGRO_EVENT* event);

    protected:

    private:
};

#endif // LOOPEDMODE_H
