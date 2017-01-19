#ifndef INTERPOLATIONMETHOD_H
#define INTERPOLATIONMETHOD_H

#include <vector>
#include "Point.h"

using namespace std;

class InterpolationMethod
{
    public:
        virtual void interpolate(vector<Point> &originalPoints, int interpolatedPointsCount, vector<Point> &interpolatedPoints) = 0;

    protected:

    private:
};

#endif // INTERPOLATIONMETHOD_H
