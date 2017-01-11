#ifndef INTERPOLATIONTESTS_H
#define INTERPOLATIONTESTS_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <iostream>

//#include "InterpolationMethod.h"
#include "LinearInterpolation.h"


using namespace std;

class InterpolationTests
{
    public:
        InterpolationTests();
        virtual ~InterpolationTests();

        static void getMouseCoordinatesOnClick();
        static void linearInterpolationTest();

    protected:

    private:
};

#endif // INTERPOLATIONTESTS_H
