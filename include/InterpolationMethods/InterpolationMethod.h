#ifndef INTERPOLATIONMETHOD_H
#define INTERPOLATIONMETHOD_H

#include <map>
#include "Point.h"

using namespace std;

class InterpolationMethod
{
    public:

        virtual ~InterpolationMethod();

        virtual void interpolate(map<int, Point> &originalPoints, map<int, Point> &interpolatedPoints) = 0;

    protected:

    private:
};

#endif // INTERPOLATIONMETHOD_H
