#ifndef SCREEN_H
#define SCREEN_H

#include "Picture.h"
#include "EventSource.h"

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"

class Screen : public EventSource
{
    public:
        Screen(int columns, int rows);
        virtual ~Screen();
        void displayPicture(Picture* picture, int x = 0, int y = 0);

        void registerIn(ALLEGRO_EVENT_QUEUE* event_queue);

    protected:

    private:
        ALLEGRO_DISPLAY * display;

        int rows;
        int columns;

        void copyPixelsToScreenBuffer(Picture* picture, int x, int y);
        void updateScreen();
};

#endif // SCREEN_H
