#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int x, int y);
        virtual ~Point();

        int getX();
        int getY();

        void setX(int x);
        void setY(int y);

    protected:

    private:
        int x;
        int y;
};

#endif // POINT_H
