#ifndef LINEARINTERPOLATION_H
#define LINEARINTERPOLATION_H

#include "InterpolationMethod.h"
#include <math.h>

#include <iostream>

class LinearInterpolation : public InterpolationMethod
{
    public:
        LinearInterpolation();
        virtual ~LinearInterpolation();

        void interpolate(vector<Point> &originalPoints, int interpolatedPointsCount, vector<Point> &interpolatedPoints);

    protected:

    private:
};

#endif // LINEARINTERPOLATION_H
