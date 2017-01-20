#include "InterpolationMethods/LinearInterpolation.h"

using namespace std;

LinearInterpolation::LinearInterpolation()
{
    //ctor
}

LinearInterpolation::~LinearInterpolation()
{
    //dtor
}

void LinearInterpolation::interpolate(map<int, Point> & originalPoints, map<int, Point>& interpolatedPoints) {

    if (originalPoints.size() < 2) {
        interpolatedPoints = originalPoints;
        return;
    }

    map<int, Point>::iterator current = originalPoints.begin();
    map<int, Point>::iterator next = (++originalPoints.begin());
    while ( next != originalPoints.end() ) {

        int x0 = (current->second).getX();
        int y0 = (current->second).getY();

        int x1 = (next->second).getX();
        int y1 = (next->second).getY();

        int interpolatedPointsCount = (next->first - current->first) + 1;
        double step = 1.0 / (interpolatedPointsCount - 1);

        int currentIndex =  current->first;

        // x0 + m * (x1 - x0)
        for ( int i = 0; i < interpolatedPointsCount; i++) {
            double m = step * i;
            int interpolatedX = round(   x0 + m * ( x1 - x0 )    );
            int interpolatedY = round(   y0 + m * ( y1 - y0 )    );

            interpolatedPoints.insert( pair<int, Point>( currentIndex, Point(interpolatedX, interpolatedY) ) );
            currentIndex++;
        }
        ++current;
        ++next;
    }
}
