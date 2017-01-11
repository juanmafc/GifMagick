#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "allegro5/allegro.h"
#include "Gif.h"
#include "Picture.h"
#include "Screen.h"
#include "Clock.h"

class MainController
{
    public:
        MainController();
        virtual ~MainController();

        void startMainLoop(string gifPath);

    protected:

    private:

};

#endif // MAINCONTROLLER_H
