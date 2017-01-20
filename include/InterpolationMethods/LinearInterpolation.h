#ifndef LINEARINTERPOLATION_H
#define LINEARINTERPOLATION_H

#include "InterpolationMethod.h"
#include <math.h>
#include <iterator>

#include <iostream>

class LinearInterpolation : public InterpolationMethod
{
    public:
        LinearInterpolation();
        virtual ~LinearInterpolation();


        virtual void interpolate(map<int, Point> &originalPoints, map<int, Point> &interpolatedPoints);

    protected:

    private:
};

#endif // LINEARINTERPOLATION_H
