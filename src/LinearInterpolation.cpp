#include "LinearInterpolation.h"

using namespace std;

LinearInterpolation::LinearInterpolation()
{
    //ctor
}

LinearInterpolation::~LinearInterpolation()
{
    //dtor
}

void LinearInterpolation::interpolate(vector<Point> &originalPoints, int interpolatedPointsCount, vector<Point> &interpolatedPoints) {
    if ( originalPoints.size() < 2) {
        return;
    }

    double step = 1.0 / (interpolatedPointsCount - 1);

    int x0 = originalPoints[0].getX();
    int y0 = originalPoints[0].getY();

    int x1 = originalPoints[1].getX();
    int y1 = originalPoints[1].getY();

    // x0 + m * (x1 - x0)
    //for ( double m = 0; m <= 1; m = m + step) {
    //for ( double m = 0; m <= step*(interpolatedPointsCount - 1); m += step) {
    for ( int i = 0; i < interpolatedPointsCount; i++) {
        double m = step * i;
        int interpolatedX = round(   x0 + m * ( x1 - x0 )    );
        int interpolatedY = round(   y0 + m * ( y1 - y0 )    );
        interpolatedPoints.push_back( Point(interpolatedX, interpolatedY) );
    }
}
